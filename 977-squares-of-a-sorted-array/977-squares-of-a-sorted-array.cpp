class Solution {
    #include<cmath>
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int ei=n-1;
        vector<int> res(n,0);
        int l=0;
        int r=n-1;
        
        while(ei>=0){
            if(abs(nums[l])>abs(nums[r])){
                res[ei--]=pow(nums[l++],2);
            }
            else{
                res[ei--]=pow(nums[r--],2);
            }
            
            
        }
        return res;
    }
};