class Solution {
    int cherryPick(vector<vector<int>>& grid, int r1, int c1, int r2, int c2, int ****dp){
        int m=grid.size();
        int n=grid[0].size();
        
        //out of bound
        if(c1<0||c1>=n||c2<0||c2>=n)
            return INT_MIN;
        
        if(dp[r1][c1][r2][c2]!=-1)
            return dp[r1][c1][r2][c2];
        
        //base case
        if(r1==m-1 && c1!=c2)
            return  dp[r1][c1][r2][c2]=grid[m-1][c1] + grid[m-1][c2];
        if(r1==m-1)
            return  dp[r1][c1][r2][c2]=grid[m-1][c1];
                
        int cherries=0;
        if(r1==r2 && c1==c2)
            cherries+=grid[r1][c1];
        else
            cherries=grid[r1][c1] + grid[r2][c2];
        vector<int> ans(9);
        ans[0]= cherries+cherryPick(grid, r1+1, c1-1, r2+1, c2-1,dp);//dl dl
        ans[1]= cherries+cherryPick(grid, r1+1, c1, r2+1, c2,dp);//dd dd
        ans[2]= cherries+cherryPick(grid, r1+1, c1+1, r2+1, c2+1,dp);//dr dr
        ans[3]= cherries+cherryPick(grid, r1+1, c1-1, r2+1, c2,dp);//dl d
        ans[4]= cherries+cherryPick(grid, r1+1, c1-1, r2+1, c2+1,dp);//dl dr
        ans[5]= cherries+cherryPick(grid, r1+1, c1+1, r2+1, c2-1,dp);//dr dl
        ans[6]= cherries+cherryPick(grid, r1+1, c1+1, r2+1, c2,dp);//dr d
        ans[7]= cherries+cherryPick(grid, r1+1, c1, r2+1, c2-1,dp);//d dl
        ans[8]= cherries+cherryPick(grid, r1+1, c1, r2+1, c2+1,dp);//d dr
        
        return dp[r1][c1][r2][c2]=*max_element(ans.begin(),ans.end());
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ****dp=new int ***[m];
        for(int i=0;i<m;i++){
            dp[i]=new int**[n];
            for(int j=0;j<n;j++){
                dp[i][j]=new int*[m];
                for(int k=0;k<m;k++){
                    dp[i][j][k]=new int[n];
                    for(int l=0;l<n;l++)
                        dp[i][j][k][l]=-1;
                }
            }
        }
        
        return cherryPick(grid, 0, 0, 0, grid[0].size()-1,dp);
    }
};