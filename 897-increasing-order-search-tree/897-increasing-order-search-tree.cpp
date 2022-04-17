
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)
            return nullptr;
        root->right=increasingBST(root->right);
        if(root->left==nullptr)
            return root;
        
        TreeNode* headn=increasingBST(root->left);
        TreeNode* temp=headn;
        root->left=nullptr;
        while(temp!=NULL&&temp->right!=NULL)
            temp=temp->right;
        temp->right=root;
        
        return headn;
    }
};