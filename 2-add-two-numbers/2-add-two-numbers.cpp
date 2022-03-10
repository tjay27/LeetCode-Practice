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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int c){
        ListNode* s=new ListNode(c);
        //base case
        if(l1==NULL&&l2==NULL){
            if(c==1)
                return s;
            else
                return NULL;
        }
        
        
        //small calculations
            //if l1 is small
            //if l2 is small
        int carry=0;
        if(l1==NULL){
            s->val+=l2->val;
            if(s->val>9){
                s->val%=10;
                carry=1;
            }
            s->next=addTwoNumbers(NULL,l2->next,carry);
        }
        else if(l2==NULL){
            s->val+=l1->val;
            if(s->val>9){
                s->val%=10;
                carry=1;
            }
            s->next=addTwoNumbers(l1->next,NULL,carry);
        }
        else{
            s->val+=l1->val;
            s->val+=l2->val;
            
            if(s->val>9){
                s->val%=10;
                carry=1;
            }
            s->next=addTwoNumbers(l1->next,l2->next,carry);
        }
        
        return s;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1,l2,0);
    }
};