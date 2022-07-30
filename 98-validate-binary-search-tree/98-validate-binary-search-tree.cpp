class Solution {
    //Not a good time complexity
    //O(n)
    //O(n)
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
    bool isValid(TreeNode* root, long min, long max){
        if(root==NULL)
            return true;
        if(root->val>min&&root->val<max){
            bool leftAns=isValid(root->left, min, root->val);
            bool rightAns=isValid(root->right, root->val, max);
            return leftAns&rightAns;
        }
        return false;
        
    }
public:
    /*bool isValidBST(TreeNode* root) {
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
    }*/
    bool isValidBST(TreeNode* root) {
        //cout<<LONG_MIN;
        return isValid(root, LONG_MIN, LONG_MAX);   
    }
};