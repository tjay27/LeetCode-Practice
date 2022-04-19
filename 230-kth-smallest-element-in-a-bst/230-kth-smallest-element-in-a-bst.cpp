class Solution {
public:
    #include<queue>
    void hlpr(TreeNode* root, queue<int>&vals){
        if(root==NULL)
            return ;
        hlpr(root->left,vals);
        vals.push(root->val);
        hlpr(root->right,vals);
        return ;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        queue<int> vals;
        hlpr(root,vals);
        
        while(k>1){
            cout<<vals.front();
            vals.pop();
            k--;
        }
        int x=vals.front();
        while(!vals.empty()){
            cout<<vals.front();
            vals.pop();
        }
        return x;
    }
};