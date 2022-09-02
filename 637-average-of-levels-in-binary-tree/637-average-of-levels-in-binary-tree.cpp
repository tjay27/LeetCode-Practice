class Solution {    
    #include<bits/stdc++.h>
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        //level order traversal
        queue<TreeNode*> pendingNodes;
        vector<double> avgVals;
        if(root==nullptr)
            return avgVals;
        pendingNodes.push(root);
        
        
        int k=1;
        while(!pendingNodes.empty()){
            int n=k;
            double ans=0;
            int x=0;
            while(k--){
                TreeNode* top=pendingNodes.front();   
                pendingNodes.pop();
                ans+=top->val;
                if(top->left){
                    x++;
                    pendingNodes.push(top->left);
                }
                if(top->right){
                    x++;
                    pendingNodes.push(top->right);
                }
            }
            ans/=n;
            avgVals.push_back(ans);
            k=x;
        }
        return avgVals;    
    }
};

