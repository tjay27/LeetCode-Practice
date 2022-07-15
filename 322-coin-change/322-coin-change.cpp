class Solution {
public:
        //unbounded knapsack
    int coinChange_rec(vector<int>& coins, int amount, int n,vector<vector<int>> &dp){
        if(amount==0)
            return 0                                                                              ;
        if(n==0)
            return -1;
        if(dp[n][amount]!=0)
            return dp[n][amount];
        int a=0;
        int b=coinChange_rec(coins, amount,n-1,dp);
        if(coins[n-1]<=amount){ 
            a=coinChange_rec(coins, amount-coins[n-1], n, dp);
            if(a==-1||b==-1){
                if(a==-1&&b==-1){
                    return dp[n][amount]=-1;
                }
                if(a==-1){
                    return dp[n][amount]=b;
                }
                if(b==-1){
                    return dp[n][amount]=1+a;
                }
                
            }
            return dp[n][amount]=min(1+a,b);
        }
        return dp[n][amount]=b;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        return coinChange_rec(coins,amount,coins.size(),dp);
    }
};