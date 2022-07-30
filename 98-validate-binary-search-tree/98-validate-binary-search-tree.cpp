class Solution {
    TreeNode* max(TreeNode* root){
        if(root==NULL)
            return root;
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    TreeNode* min(TreeNode* root){
        if(root==NULL)
            return root;
        while(root->left!=NULL)
            root=root->left;
        return root;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(!root->left&&!root->right)
            return true;
        if(isValidBST(root->left)&&isValidBST(root->right)){
            TreeNode* maxLeft=max(root->left);
            TreeNode* minRight=min(root->right);
            if(maxLeft!=NULL&&minRight!=NULL)
                return maxLeft->val<root->val && minRight->val>root->val;
            if(maxLeft==NULL)
                return minRight->val>root->val;
            if(minRight==NULL)
                return maxLeft->val<root->val;
        }
        return false;
    }
};