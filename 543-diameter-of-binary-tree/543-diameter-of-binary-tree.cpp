class Solution {
public:
    
    pair<int,int> d(TreeNode* root){
        pair<int,int> ans;
            ans.first=0;
            ans.second=0;
        if(root==NULL){
            return ans;
        }
        
        pair<int,int> left=d(root->left);
        pair<int,int> right=d(root->right);
        
        int d1=left.first;
        int d2=right.first;
        int h1=left.second;
        int h2=right.second;
        
        //
        ans.first=max(d1,max(d2,h1+h2));
        ans.second=1+max(h1,h2);
        
        return ans;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
         return  d(root).first;
    }
};