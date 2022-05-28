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
    #define lli long long int 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //convert to normal numbers
        //then create a new list
        vector<int> n1;
        vector<int> n2;
        
        ListNode* temp=l1;
        while(temp!=NULL){
            n1.push_back(temp->val);
            temp=temp->next;
        }
        
        temp=l2;
        while(temp!=NULL){
            n2.push_back(temp->val);
            temp=temp->next;
        }
        //lli n=n1+n2; //final number
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        
        ListNode* head=NULL;
        int i=0;
        int j=0;
        int len1=n1.size();
        int len2=n2.size();
        int carry=0;
        while(i<n1.size()&&j<n2.size()){
            
            int x=n1[i]+n2[j]+carry;
            if(x>9)
                carry=1;
            else 
                carry=0;
            ListNode* newNode=new ListNode(x%10);       
            newNode->next=head;
            head=newNode;
            //n/=10;     
            i++;
            j++;
            
        }
        
        while(i<len1){
            int x=n1[i]+carry;
            if(x>9)
                carry=1;
            else 
                carry=0;
            ListNode* newNode=new ListNode(x%10);       
            newNode->next=head;
            head=newNode;    
            i++; 
        }
        
        while(j<len2){
            int x=n2[j]+carry;
            if(x>9)
                carry=1;
            else 
                carry=0;
            ListNode* newNode=new ListNode(x%10);       
            newNode->next=head;
            head=newNode;
            j++;
        }
        
        if(carry==1){
            ListNode* newNode=new ListNode(carry);       
            newNode->next=head;
            head=newNode;
        }
        if(head==NULL)
            head=new ListNode(0);
        return head;
    }
};