class Solution {
public:
    vector<vector<int>> shiftGrid2(vector<vector<int>>& grid, int k){
        if(k==0)
            return grid;
        //shift by 1
        int m=grid.size();
        int n=grid[0].size();
        //store the last element
        int temp=grid[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                grid[i][j+1]=grid[i][j];
            }
            if(i!=0)
                grid[i][0]=grid[i-1][n-1];
        }
        
        grid[0][0]=temp;;
        
        return shiftGrid2(grid,k-1);
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        k%=grid.size()*grid[0].size();
        return shiftGrid2(grid,k);
    }
};