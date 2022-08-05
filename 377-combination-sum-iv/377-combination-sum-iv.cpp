class Solution {
    int combsum(vector<int>& nums, int target, int endInd,int n, vector<vector<int>> &dp){
        //base case
        if(target==0)
            return 1;
        if(endInd==-1)
            return 0;
        if(dp[endInd][target]!=-1)
            return dp[endInd][target];
        int take=0;
        int notTake=combsum(nums,target,endInd-1,n,dp);
        if(nums[endInd]<=target){
            int take=combsum(nums,target-nums[endInd],n-1,n,dp);
            return dp[endInd][target]=take+notTake;
        }
        return dp[endInd][target]=notTake;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return combsum(nums,target,nums.size()-1,nums.size(),dp);
        
    }
};
// class Solution { // this problem
//     public int combinationSum4(int[] nums, int target) {
//         int n=nums.length;
//         return count(nums, target, n-1, n);
//     }
    
//     private int count(int[] nums, int target, int pos,int n) {
//         if (pos == -1 || target <= 0) {
//             return (target == 0) ? 1 : 0;
//         }
//         int take=0;
//         int skip = count(nums, target, pos - 1, n);
//         if(nums[pos]<=target){
//              take = count(nums, target - nums[pos], n-1, n);
//              return take+skip;
//         }
        
        
//         return   skip;
//     }
// }

