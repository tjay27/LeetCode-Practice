/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* rootH;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
       rootH=root;
    }
    
    int next() {
        //iterative method
        if(rootH!=NULL||!st.empty()){
            while(rootH!=NULL){
                st.push(rootH);
                rootH=rootH->left;
            }
        } 
        int ans=st.top()->val;
        rootH=st.top();
        st.pop();
        rootH=rootH->right;
        return ans;
    }
    
    bool hasNext() {
    
       if(rootH==NULL&&st.empty())
           return false;
       return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */