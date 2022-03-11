/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* rotateRighte(ListNode* head, int k) {
        //recursive function
        if(k==0||head==NULL||head->next==NULL)
            return head;
        
        ListNode* temp=head;
        
        
        while(temp->next->next!=NULL){
            temp=temp->next;
        //    l++;
        }
        
        
        temp->next->next=head;
        head=temp->next;
        temp->next=NULL;
        return rotateRighte(head,k-1);
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==NULL)
            return head;
        
        ListNode* temp=head;
        
        int l=0;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        k%=l;
        
        
        return rotateRighte(head,k);
    }
};