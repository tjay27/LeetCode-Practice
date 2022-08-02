class Solution {
void dfs(int i, int j, int m, int n, vector<vector<char>> &grid, vector<vector<int>> &visited){
    //cout<<i<<' '<<j<<endl;
    if(i==m||j==n||i<0||j<0)
        return ;
    if(grid[i][j]=='0')
        return ;
    if(visited[i][j]==1)
        return ;
    visited[i][j]=1;
   // cout<<"called:"<<i<<' '<<"called:"<<j<<endl;
    //calling dfs on all the connected components
    dfs(i+1,j,m,n,grid,visited);
    dfs(i-1,j,m,n,grid,visited);
    dfs(i,j+1,m,n,grid,visited);
    dfs(i,j-1,m,n,grid,visited);
    
    return ;
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        int noOfComponents=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!='0'&&visited[i][j]!=1){
                    //cout<<i<<' '<<j<<endl;
                    dfs(i,j,m,n,grid,visited);
                    noOfComponents++;   
                }
            }
        }
        return noOfComponents;
    }
};