
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL)
            return NULL;
        if(root==p||root==q)
            return root;
        //look for the ancestor in left half
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        //look for the ancestor in right half
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        if(!left&&!right)
            return NULL;
        if(left&&right)
            return root;
        if(!left&&right){
            return right;
        }
        return left;
    }
};