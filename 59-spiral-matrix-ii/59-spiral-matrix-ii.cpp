class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            vector<int> p(n);
            arr.push_back(p);
        }
        
        int n2=(n+1)/2;
        int c=1;
        for(int i=0;i<n2;i++){
                //top
                for(int j=i;j<n-i;j++){
                    arr[i][j]=c;
                    c++;
                } 
                /*//top
                for(int j=i;j<n-i;j++){
                    arr[i][j]=c;
                    c++;
                }
                if(c>n*n)
                    break;
                //right
                for(int k=i+1;k<n-i;k++){
                    arr[n-i][k]=c;
                    c++;
                }
                if(c>n*n)
                    break;
                //bottom
                for(int k=n-i-1;k>=0;k--){
                    
                }
                if(c>n*n)
                    break;
                //left
                
                
                if(c>n*n)
                    break;*/
                
            
                //left 
               for(int k=i+1;k<n-i;k++){
                    arr[k][n-i-1]=c;
                    c++;
               }
                if(c>n*n)
                    break;
                //bottom
                for(int j=n-i-2;j>=i;j--){
                    arr[n-i-1][j]=c;
                    c++;
                }
                if(c>n*n)
                    break;
                //right
                for(int k=n-i-2;k>i;k--){
                    arr[k][i]=c;
                    c++;
                }
                    
                if(c>n*n)
                    break;
            
        }
        return arr;
    }
};