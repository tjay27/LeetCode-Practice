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
       //initialisation 
        // vector<int> prev(sum+1);
        // vector<int> curr(sum+1);
        vector<int> dp(sum+1);
        for(int i=0;i<=sum;i++){
            dp[i]=0;
        }
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=sum;j>=0;j--){
                if(nums[i-1]<=j){
                    dp[j]=dp[j-nums[i-1]]+dp[j];
                }
                else
                    dp[j]=dp[j];
            }
        }
        return dp[sum];
    }
};