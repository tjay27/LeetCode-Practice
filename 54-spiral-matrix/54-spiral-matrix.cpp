class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        //cout<<row;
        int col=matrix[0].size();
        //cout<<col;
        int top=0;
        int left=0;
        int down=row-1;
        int right=col-1;
        int dir=0;
        
        vector<int> v;
        
        while(top<=down && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    v.push_back(matrix[top][i]);
                    cout<<matrix[top][i];
                    
                    
                }
                dir=(dir+1)%4;
                top++;
            }
            else if(dir==1){
                for(int i=top;i<=down;i++){
                    v.push_back(matrix[i][right]);
                    cout<<matrix[i][right];
                    
                }
                dir=(dir+1)%4;
                    right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    v.push_back(matrix[down][i]);
                    cout<<matrix[down][i];
                                    }
                dir=(dir+1)%4;
                    down--;

            }
            else if(dir==3){
                for(int i=down;i>=top;i--){
                    v.push_back(matrix[i][left]);
                                    }
                left++;
                    dir=(dir+1)%4;

            }
            //cout<<"dir="<<dir;
        }
        return v;
        
    }
};