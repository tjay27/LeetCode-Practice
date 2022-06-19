class BSTIterator {
    TreeNode* curr;
    stack<TreeNode*> st;
    
public:
    BSTIterator(TreeNode* root) {
        curr=root;
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }    
        
    }
    
    int next() {
        curr=st.top();
        int t=curr->val;
        st.pop();
        curr=curr->right;
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;    
        }
        return t;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

