class Solution {
    vector<TreeNode*> gen(int start, int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
                    
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTrees=gen(start,i-1);
            vector<TreeNode*> rightTrees=gen(i+1,end);
            for(int j=0;j<leftTrees.size();j++){
                for(int k=0;k<rightTrees.size();k++){
                    TreeNode* root=new TreeNode(i);
                    root->left=leftTrees[j];
                    root->right=rightTrees[k];
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
        
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return gen(1,n);
    }
};