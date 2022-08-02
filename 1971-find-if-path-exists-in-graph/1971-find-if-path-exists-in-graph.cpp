// class Solution {
// #include<vector>
// bool pathExists(int start,vector<vector<int>> adjList, vector<int>&visited,int dest){
//     if(start==dest)
//         return true;
//     visited[start]=1;
//     for(int j=0;j<adjList[start].size();j++){
//         if(visited[adjList[start][j]]!=1){
//             bool ans=pathExists(adjList[start][j],adjList,visited,dest);
//             if(ans)
//                 return ans;
//         }
//     }

//     return false;
// }

// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         //construct adjList
//         vector<int> visited(n,0);
//         vector<vector<int>> adjList(n);
//         for(int i=0;i<edges.size();i++){
//             int a=edges[i][0];
//             int b=edges[i][1];
//             adjList[a].push_back(b);
//             adjList[b].push_back(a);
//         }
        
        
//        return pathExists(source, adjList, visited, destination);
//        return true; 
//     }
// };
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);        
        stack<int> st;
        st.push(start);
        visited[start] = 1; 
        
        while(!st.empty()){ 
            auto top = st.top();
            if(top == end)
                return 1;
            st.pop();
            for(auto node : graph[top]){
                if(!visited[node]){
                    visited[node] = 1;
                    st.push(node); 
                }
            }
        }
        return false;
    }
};