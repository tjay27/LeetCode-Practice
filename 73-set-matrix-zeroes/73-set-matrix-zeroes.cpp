class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> nums;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                
                if(matrix[i][j]==0){
                    pair<int,int> v;
                    v.first=i;
                    v.second=j;
                    nums.push_back(v);
            }
                
                
                
                
                
            }
        }   
        
        for(int k=0;k<nums.size();k++){
            for(int i=0;i<matrix.size();i++){
                matrix[i][nums[k].second]=0;
            }
            for(int j=0;j<matrix[0].size();j++){
                matrix[nums[k].first][j]=0;
            }
        }
        
        
        
        return ;
    }
};