class Solution {
    int climb(int n, vector<int>& dp){
        if(n==0){
            dp[0]=1;
        }
        if(n==1){
            dp[1]=1;
        }
        if(dp[n]==0){
            dp[n]=climb(n-1,dp)+climb(n-2,dp);
        }
        return dp[n];
        
    }
public:
    int climbStairs(int n) {
        //recursive
        /*if(n==0)
            return 1;
        if(n==1) //if one step
            return 1; //only one way
         
        int w1=climbStairs(n-1);//no of ways to n-1 steps
        int w2=climbStairs(n-2);//no of ways to n-2 steps
        
        return w1+w2;*/
        
        //memo
        
        vector<int> dp(n+1,0);
        return climb(n,dp);
        
    }
};