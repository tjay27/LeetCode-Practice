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
       // vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        //initialisation
        
        vector<int> prev(sum+1);
        vector<int> curr(sum+1);
        for(int i=0;i<=sum;i++){
            prev[i]=0;
        }
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]<=j){
                    curr[j]=prev[j-nums[i-1]]+prev[j];
                }
                else
                    curr[j]=prev[j];
            }
            prev=curr;
        }
        return curr[sum];
    }
};