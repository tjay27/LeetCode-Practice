class Solution {
public:

    void rotate(vector<vector<int>>& arr) {
        /*int n=arr.size();
        int l=arr.size()/2;
        
        int i=0,j=0;
        
        while(l--){
            int temp=arr[i][j];
            //shift left
            for(int k=i+1;k<n-i;k++){
                arr[k-1][j]=arr[k][j];
            }            
            //shift bottom
            for(int k=j+1;k<n-i;k++){
                arr[n-i-1][k-1]=arr[n-i-1][k];
            }
            //shift right
            for(int k=n-i-2;k>=i;k--){
                arr[k-1][n-1-j]=arr[k][n-1-j];
            }
            //shift top
            for(int k=n-i-1;k>=i;k--){
                arr[i][k+1]=arr[i][k];
            }
            i++;
            j++;
            arr[i+1][j+2]=temp;
        }
        
        return ;*/
        
        //reverse and transpose
        int n=arr.size();
        for(int k=0;k<n;k++){
            //std::reverse(arr[i].begin(),arr[i].end());
            int i=0, j=n-1;
            while(i<j){
                //swap
                int t=arr[i][k];
                arr[i][k]=arr[j][k];
                arr[j][k]=t;
                i++;
                j--;
            }
        }
        
        //transpose
        for(int i=0;i<n;i++){
            //swap
            for(int j=i;j<n;j++){
                int t=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=t;
            }
        }
            
        return ;
    }
};