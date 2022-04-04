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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temph=head;
        ListNode* tempt=head;
        k-=1;
        
        int len=0;
        while(tempt!=NULL){
            tempt=tempt->next;
            len++;
        }
        tempt=head;
        int z=len-k-1;
        
        while(k--){
            temph=temph->next;    
        }
        
        while(z--){
            tempt=tempt->next;
        }
        
        cout<<temph->val<<' '<<tempt->val<<endl;
        int t=temph->val;
        temph->val=tempt->val;
        tempt->val=t;
        return head;
    }
    
};