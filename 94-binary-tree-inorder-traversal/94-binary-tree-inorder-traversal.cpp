class Solution {
    //recursive
    void inorder(TreeNode* root, vector<int> &ans){
        if(root==NULL)
            return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    //Inorder Iterative is Recursion with a Stack space of your own
    void inorderIt(TreeNode* root, vector<int> &ans){
        stack<TreeNode*> st;
       
        while(root!=NULL||!st.empty()){
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            ans.push_back(st.top()->val);
            root=st.top()->right;
            st.pop();
        }
        
        return ;
}   
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderIt(root,ans);
        return ans;
    }
};




