class Solution {
#include<vector>
#include<stack>
bool pathExists(int start,vector<vector<int>> adjList, vector<int>&visited,int dest){
    if(start==dest)
        return true;
    visited[start]=1;
    for(int j=0;j<adjList[start].size();j++){
        if(visited[adjList[start][j]]!=1){
            bool ans=pathExists(adjList[start][j],adjList,visited,dest);
            if(ans)
                return ans;
        }
    }

    return false;
}
bool dfs_iter(int start,vector<vector<int>> adjList, vector<int>&visited,int end){
    if(start==end)
        return true;
    visited[start]=true;
    stack<int> st;
    st.push(start);
    while(!st.empty()){
        int front=st.top();
        st.pop();
        for(auto i: adjList[front]){
            if(visited[i]==1)
                continue;
            st.push(i);
            visited[i]=1;
            if(i==end)
                return true;
        }
    }
    
    return false;
}

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //construct adjList
        vector<int> visited(n,0);
        vector<vector<int>> adjList(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        
        
       return dfs_iter(source, adjList, visited, destination);

    }
};
