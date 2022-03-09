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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=head;
        
        //delete nodes
        bool dupExists=false;
        
        while(curr!=NULL&&curr->next!=NULL){
            temp=curr->next;
            
            while(curr!=NULL&&curr->next!=NULL&&curr->val==temp->val){
                if(dupExists==false)
                    dupExists=true;
                //delete temp
                ListNode* n=temp;
                temp=temp->next;
                delete n;
                curr->next=temp;
                
            }
            if(dupExists==true){
                //delete curr
                
                //if curr=head
                if(curr==head){
                    delete curr;
                    head=temp;
                    curr=temp;
                }
                //else
                else{
                    delete curr;
                    prev->next=temp;
                    curr=temp;
                    
                }
                dupExists=false;
                
            }  
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;      
    }
};