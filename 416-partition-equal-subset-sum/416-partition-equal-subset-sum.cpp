class Solution {
public:
    bool subsetSumK(vector<int>& arr,int k,int n){
        //base case
        /*
        if(n==0){
            return false;
        }
        if(k==0)
            return true;
        
        //decision tree
        if(nums[n-1]<=k){
            bool incl=subsetSumK(nums,k-nums[n-1],n-1);
            bool notincl=subsetSumK(nums,k,n-1);
            return incl||notincl;
        }
        bool notincl=subsetSumK(nums,k,n-1);
        
        return notincl;
        */
        //DP Approach
        vector<vector<bool>> dp; //dp[n+1][k+1]
        for(int i=0;i<=n;i++)
        {
            vector<bool> v(k+1);
            dp.push_back(v);
        }
        //initialising with base case
        for(int j=0;j<=k;j++)
            dp[0][j]=false;
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        
        //FILLING THE REST OF THE BLOCKS
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(arr[i-1]<=j){
                    //incl || not incl
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][k];
               
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        if(sum%2==0)
            return subsetSumK(nums,sum/2,nums.size());
        return false;
    }
};