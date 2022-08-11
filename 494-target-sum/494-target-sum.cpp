class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(auto &i:nums)
            s+=i;
        if(abs(target)>s)
            return 0;
        int sum=(s+target)/2;
        if((s+target)%2!=0)
            return 0;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        //initialisation
        for(int i=0;i<=sum;i++){
            dp[0][i]=0;
        }
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};