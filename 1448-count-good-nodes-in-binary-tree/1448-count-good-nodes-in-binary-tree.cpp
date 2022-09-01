class Solution {
    int goodNodes(TreeNode* root, int maxtillnow){
        if(root==NULL)
            return 0;
        if(root->val>=maxtillnow)
            return 1+goodNodes(root->left,max(maxtillnow,root->val))+goodNodes(root->right,max(maxtillnow,root->val));
        return goodNodes(root->left,max(maxtillnow,root->val))+goodNodes(root->right,max(maxtillnow,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root,INT_MIN);
    }
};