class Solution {
    int eggDrop(int k, int n, vector<vector<int>> &dp){
        //base case
        if(k==1)
            return n;
        if(n<=1)
            return n;
        if(dp[k][n]!=-1)
            return dp[k][n];
        
        //for traversing from 1 to n, you use binary search instead
        int lo=1;
        int hi=n;
        
        int ans=INT_MAX;
        while(lo<=hi){
            int mid= (lo) + (hi-lo)/2;
            //break at mid
            int mbreak=eggDrop(k-1,mid-1,dp);
            int mnobreak=eggDrop(k, n - mid, dp);
            int worstCase=1+max(mbreak, mnobreak);
            
            if(mbreak<mnobreak){
                lo=mid+1;
            }
            
            else{
                hi=mid-1;
            }
            
            
            ans=min(ans,worstCase);
            
        }
        return dp[k][n]=ans;
        
    }
public:
    int superEggDrop(int k, int n) {
        //base case
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return eggDrop(k,n,dp);
        if(k==1)
            return n;
        if(n==0||n==1)
            return n;
        //for loop
        //choosing the floor to drop egg from
        int finalAns=INT_MAX;
        for(int i=1;i<=n;i++){
            int breaks=superEggDrop(k-1,i-1);
            int noBreaks=superEggDrop(k,n-i);
            //maximum in both possibilites
            int worstCase=1+max(breaks,noBreaks);
            finalAns=min(finalAns, worstCase);
        }
        return finalAns;
    }
};