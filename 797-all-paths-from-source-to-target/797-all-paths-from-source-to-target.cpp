class Solution {
    void dfs(int i,int end,vector<vector<int>>& graph,vector<int> temp, vector<vector<int>> &ans){
        temp.push_back(i);
                
        if(i==end){
            ans.push_back(temp);
            return ;
        }
        for(int j=0;j<graph[i].size();j++){
            dfs(graph[i][j],end,graph,temp,ans);
        }
        return ;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n=graph.size();
        dfs(0,n-1,graph,temp,ans);
        return ans;
    }
};