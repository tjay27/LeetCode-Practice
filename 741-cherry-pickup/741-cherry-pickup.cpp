class Solution {
    int allMinus1(vector<vector<int>>& grid, int i, bool top){
        int m=grid.size();
        int n=grid[0].size();
        //2 pointer approach
        int i1=i;
        int j1=0;
        int i2=0;
        int j2=i;
        int k=i;
        if(top==true){
            while(i>0){
                if((grid[i1][j1]!=-1 || grid[i2][j2]!=-1))
                    return false;
                else{
                    i1--;
                    j1++;
                    i2++;
                    j2--;
                }
                i--;
            }
            return true;
        }
        
        else{
            while(i>0){
                
                if((grid[m-1-i1][n-1-j1]!=-1||grid[m-1-i2][n-1-j2]!=-1)){
                    return false;
                }
                else{
                    i1--;
                    j1++;
                    i2++;
                    j2--;
                }
                i--;
            }
            return true;
        }      
    }
    
    int topToDown_dp(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        //if either of the diagonals is -1, answer will be zero
        for(int i=1;i<m;i++){
            int a=allMinus1(grid,i,true);
            int b=allMinus1(grid,i,false);
            if(a||b)
                return 0;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //handling cases where answer will be zero
                if(i==1 && j==1){
                    dp[i][j]=grid[i-1][j-1];
                    continue;
                }
                //all cases where answer will be zero
                if(grid[i-1][j-1]==-1)
                    dp[i][j]=0;
                if(i==1||j==1){
                    
                    if(i==1 && grid[i-1][j-2]==-1){
                        dp[i][j]=0;
                        continue;
                    }
                    else if(j==1 && grid[i-2][j-1]==-1){
                        dp[i][j]=0;
                        continue;
                    }
                    
                }
                else if(i>1 && j>1){
                    if(grid[i-2][j-1]==-1 && grid[i-1][j-2]==-1){
                        dp[i][j]=0;
                        continue;
                    }
                }
                //answer is notzero
                if(grid[i-1][j-1]==1){
                    dp[i][j]=1+max(dp[i][j-1],dp[i-1][j]);
                }
                else if(grid[i-1][j-1]==0){
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
                
            }
        }
                
        int pick1=dp[m][n];    
        cout<<pick1<<endl;
        //backtracking and marking visited paths has 0
        int i=m;
        int j=n;
        while(i>0 && j>0){
            if(grid[i-1][j-1]==1){
                grid[i-1][j-1]=0;
            }
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else if(dp[i-1][j]<dp[i][j-1]){
                grid[i-1][j-1]=0;
                j--;
            }
            else
                j--;
        } 
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //handling cases where answer will be zero
                if(i==1 && j==1){
                    dp[i][j]=grid[i-1][j-1];
                    continue;
                }
                //all cases where answer will be zero
                if(grid[i-1][j-1]==-1)
                    dp[i][j]=0;
                if(i==1||j==1){
                    
                    if(i==1 && grid[i-1][j-2]==-1){
                        dp[i][j]=0;
                        continue;
                    }
                    else if(j==1 && grid[i-2][j-1]==-1){
                        dp[i][j]=0;
                        continue;
                    }
                    
                }
                else if(i>1 && j>1){
                    if(grid[i-2][j-1]==-1 && grid[i-1][j-2]==-1){
                        dp[i][j]=0;
                        continue;
                    }
                }
                //answer is notzero
                if(grid[i-1][j-1]==1){
                    dp[i][j]=1+max(dp[i][j-1],dp[i-1][j]);
                }
                else if(grid[i-1][j-1]==0){
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
                
            }
        }
        cout<<dp[m][n];
        return pick1+dp[m][n];
        
    }
        
    int findMaxCherries(vector<vector<int>>& grid, int r1, int c1, int r2, int c2, int ****dp){
        //base case
        if(r1>=grid.size()||r2>=grid.size()||c1>=grid.size()||c2>=grid.size()||grid[r1][c1]==-1||grid[r2][c2]==-1)
            return INT_MIN;
               
        
        if(r1==grid.size()-1 && c1==grid.size()-1)
            return grid[r1][c1];
        if(r2==grid.size()-1 && c2==grid.size()-1)
            return grid[r2][c2];
        
        if(dp[r1][c1][r2][c2]!=0)
            return dp[r1][c1][r2][c2];
        
        int cherries=0;
        if(r1==r2 && c1==c2){
            cherries=grid[r1][c1];
        }
        else{
            cherries=grid[r1][c1]+grid[r2][c2];
        }
        //recursive call
        int p1=findMaxCherries(grid, r1, c1+1, r2, c2+1, dp); //hh
        int p2=findMaxCherries(grid, r1, c1+1, r2+1, c2, dp);//hv
        int p3=findMaxCherries(grid, r1+1, c1, r2, c2+1, dp);//vh
        int p4=findMaxCherries(grid, r1+1, c1, r2+1, c2, dp);//vv
        
        return dp[r1][c1][r2][c2]=cherries+max(max(p1,p2),max(p3,p4));
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ****dp=new int***[n];
        for(int i=0;i<n;i++){
            dp[i]=new int **[n];
                for(int j=0;j<n;j++){
                    dp[i][j]=new int *[n];
                for(int k=0;k<n;k++){
                    dp[i][j][k]=new int[n];
                    for(int l=0;l<n;l++){
                        dp[i][j][k][l]=0;
                    }
                }
            }
        }
        int ans=findMaxCherries(grid, 0, 0, 0, 0,dp);
        return max(0, ans);
    }
};