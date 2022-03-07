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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        
        while(temp1!=NULL&&temp2!=NULL){
            int d1=temp1->val;
            int d2=temp2->val;
            if(d1<d2){
                if(tail==NULL){
                    head=temp1;
                    tail=temp1;
                    
                }
                else{
                    tail->next=temp1;
                    tail=temp1;
                    
                }
                temp1=temp1->next;
            }
                
            else{
                if(tail==NULL){
                    head=temp2;
                    tail=temp2;
                }
                else{
                    tail->next=temp2;
                    tail=temp2;
                }
                temp2=temp2->next;
                    
            }
        }
        while(temp1!=NULL){
            if(tail==NULL){
                return temp1;
                    
            }
            else{
                tail->next=temp1;
                return head;
            }
        }
        while(temp2!=NULL){
            if(tail==NULL){
                return temp2;
                    
            }
            else{
                tail->next=temp2;
                return head;
            }
        }
        return head;
    }
};