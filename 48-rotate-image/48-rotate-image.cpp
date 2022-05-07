class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        //naive approach-extra space and copy rows in columns
        
        int n=arr.size();
        //transpose
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
        
        //reverse
        for(int i=0;i<n;i++){
            int l=0;
            int m=n-1;
            while(l<m){
                int temp=arr[i][l];
                arr[i][l]=arr[i][m];
                arr[i][m]=temp;
                l++;
                m--;
            }
        }
        
        return;
        
        
    }
};