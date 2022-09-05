class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> pendingNode;
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        pendingNode.push(root);
        ans.push_back(vector<int>{root->val});
        
        while(!pendingNode.empty()){
            vector<int> sans;
            queue<Node*> tempNodes;
            while(!pendingNode.empty()){
                Node* front=pendingNode.front();
                pendingNode.pop();
                for(auto &i:front->children){
                    tempNodes.push(i);
                    sans.push_back(i->val);
                }
            }
            pendingNode=tempNodes;
            if(!sans.empty())
                ans.push_back(sans);
        }
        return ans;
    }
};