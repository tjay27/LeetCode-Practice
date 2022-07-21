class Solution {
    pair<ListNode*,ListNode*> reverse(ListNode* head){
        //recursive
        pair<ListNode*,ListNode*> ans;
        ans.first=NULL;
        ans.second=NULL;
        if(head==NULL)
            return ans;
        if(head->next==NULL){
            ans.first=head;
            ans.second=head;
            return ans;
        }
        ans=reverse(head->next);
        ans.second->next=head;
        ans.second=ans.second->next;
        ans.second->next=NULL;
        return ans;
        
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        
        ListNode* leftptr=head;
        ListNode* rightptr=head;
        
        if(left==1){
            int i=1;
            while(rightptr!=NULL&&i<right){
                rightptr=rightptr->next;
                i++;
            }
            ListNode* rightptrnxt=rightptr->next;
            rightptr->next=NULL;
            ListNode* tailafterReversal=head;
            
            head=reverse(head).first;
            tailafterReversal->next=rightptrnxt;
            return head;
        }
        
        
        int i=1;
        while(leftptr!=NULL&&i<left-1){
            //cout<<i<<endl;
            leftptr=leftptr->next;
            i++;
        }
        //cout<<leftptr->val<<' '<<endl;
        rightptr=leftptr;
        while(rightptr!=NULL&&i<right){
            rightptr=rightptr->next;
            i++;
        }
        //cout<<leftptr->val<<' '<<rightptr->val<<endl;
        ListNode* rightptrnxt=rightptr->next;
        rightptr->next=NULL;
        
        ListNode* leftptrnxt=leftptr->next;
        
        leftptr->next=reverse(leftptr->next).first;
        
        leftptrnxt->next=rightptrnxt;
        return head;
    }
};