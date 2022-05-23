// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    #include<queue>
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> pendingNodes;
        vector<int> ans;
        //adjacency list is given
        vector<int> visited(V,0);
        pendingNodes.push(0);
        visited[0]=1;
        while(!pendingNodes.empty()){
            int head=pendingNodes.front();
            pendingNodes.pop();
            ans.push_back(head);
            for(int i=0;i<adj[head].size();i++){
                if(visited[adj[head][i]]!=1){
                    pendingNodes.push(adj[head][i]);
                    visited[adj[head][i]]=1;
                }
            }    
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends