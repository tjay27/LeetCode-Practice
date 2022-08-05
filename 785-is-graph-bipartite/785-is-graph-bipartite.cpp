class Solution {
    bool colorGraphBFS(int sv,vector<vector<int>>& adjList,vector<int> &color){
        stack<int> pendingNodes;
        pendingNodes.push(sv);
        color[sv]=0;
        while(!pendingNodes.empty()){
            int top=pendingNodes.top();
            pendingNodes.pop();
            for(int i=0;i<adjList[top].size();i++){
                if(color[adjList[top][i]]==-1){
                    color[adjList[top][i]]=!color[top];
                    pendingNodes.push(adjList[top][i]);
                }
                else{
                    if(color[adjList[top][i]]==color[top])
                        return false;
                }
            }
            
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //we don't need visited array here because 
        // There is one purpose of graph to check if cycle there, other to check if there are multiple                  components all are traversed
        // In this question we using color array.
        //color array here is doing the work of visited array, if it is colored it means it was reached.
        int n=graph.size();
        vector<int> color(n,-1); //-1 means not colored.
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                bool isBipartite=colorGraphBFS(i,graph,color);
                if(!isBipartite)
                    return false;
            }
        }
        return true;
        
        
      
    }
};