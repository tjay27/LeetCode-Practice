/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        
        //create a copy 
        Node* headn=new Node(head->val);
        Node* tailn=headn;
        Node* temp=head;
        
        temp=temp->next;
        
        while(temp!=NULL){
            Node*n=new Node(temp->val);
            //add the new node to the new list
            tailn->next=n;
            tailn=n;
            //update temp
            temp=temp->next;
        }
        
        //create a list with index of 
        
        temp=head;
        Node* temp2=headn;
        
        
        while(temp!=NULL){  
            Node* target=temp->random;            
            Node* t1=head;
            Node* t2=headn;
            
            while(t1!=target){
                t1=t1->next;
                t2=t2->next;
            }
                 
            temp2->random=t2;
            
            
            //updating temps
            temp=temp->next;
            temp2=temp2->next;
        }
        
        
        return headn;
        
    }
};