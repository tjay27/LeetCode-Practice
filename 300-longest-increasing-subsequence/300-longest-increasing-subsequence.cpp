class Solution {
    /*
    int lis(vector<int>& nums,int n,int prev){
        //basecase
        if(n==0)
            return 0;
        
        //check if valid
        if(nums[n-1]<prev)
            return max(1+lis(nums,n-1,nums[n-1]),lis(nums,n-1,prev));
        //pass if invalid
        return lis(nums,n-1,prev);
        
    }
    
    int lis_dp(vector<int> arr, int n, vector<vector<int>> &dp){
    //prev index can't be zero therefore initialising as 0
    //in mem approach curr index goes from n-1 to -1 --> n to 0
    //prev index goes from n to 0 
    //dp[currInd][prevInd]

    //row
    for(int j=0;j<n+1;j++)
        dp[0][j]=0;
    for(int i=0;i<n+1;i++) //(i=0 is -1 and i=n is n-1)
        dp[i][0]=0;

    for(int i=1;i<n+1;i++){ 
        for(int j=i;j<n+1;j++){ //j=1 to n
        //j is prevInd
        //i-1 is currInd
            int prev=INT_MAX;
            if(j!=n)
                prev=arr[j];
            if(arr[i-1]<prev){
                int take=1+dp[i-1][i];
                int notTake=dp[i-1][j];
                dp[i][j]=max(take,notTake);
            }
            else
                dp[i][j]=dp[i-1][j];

        }    
    }
    return dp[n][n];
    
}
    
    int lis_mem(vector<int>& nums, int curr, int prev,vector<vector<int>>&dp){
        //    curr is curr index
        //    prev is prev index
        //    initially prev=n and curr=n-1
        //    if prev=n, value is INT_MAX
        
        //BASE CASE
        if(curr==-1){
            return 0;
        }
        if(dp[curr][prev]!=-1)
            return dp[curr][prev];
        int prevVal=INT_MAX;
        if(prev==nums.size())
            prevVal=INT_MAX;
        else
            prevVal=nums[prev];
        //include
        int include=1+lis_mem(nums,curr-1,curr,dp);
        int notInclude=lis_mem(nums,curr-1,prev,dp);
        if(nums[curr]<prevVal)
            return dp[curr][prev]=max(include,notInclude);
        
        return dp[curr][prev]=notInclude;
    }
    
    int lis_dp(vector<int> &nums, int n, vector<vector<int>>&dp){
        for(int i=0;i<=n;i++)
            
    }
    */
    //[0 3 1 6 2 7 7]
    //total number of operations 
    /*int lis_rec(vector<int>& nums, int curr, int prev, int n){
        //base case
        //curr 0 se n
        //prev -1 se n-1
        if(curr==n)
            return 0;
        //recursive calls
        if(prev==-1||nums[prev]<nums[curr]){
            int take=1+lis_rec(nums,curr+1,curr,n);
            int notTake=lis_rec(nums,curr+1,prev,n);
            return max(take,notTake);
        }
        int notTake=lis_rec(nums,curr+1,prev,n);
        return notTake;
        
    }
    
    int lis_mem(vector<int>& nums, int curr, int prev, int n, vector<vector<int>> &dp){
        //base case
        //n+1*n+1
        //curr goes from 0 to n
        //prev goes from -1 to n-1
        if(curr==n)
            return 0;
        
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        
        if(prev==-1||nums[prev]<nums[curr]){
            int take=1+lis_mem(nums,curr+1,curr,n,dp); //current index has been taken
            int notTake=lis_mem(nums,curr+1,prev,n,dp);
            return dp[curr][prev+1]=max(take,notTake);
        }
        
        return dp[curr][prev+1]=lis_mem(nums,curr+1,prev,n,dp);
    }
    
    int lis_mem2(vector<int>& nums, int curr, int prev, int n, vector<vector<int>> &dp){
        //curr lies between n-1 to -1 converted to 0 to n
        //prev goes from n to 0
        // 0 3 1 6 2 2 7
        if(curr==-1)
            return 0;
        if(dp[curr+1][prev]!=-1)
            return dp[curr][prev];
        if(prev==n||nums[curr]<nums[prev]){
            int take=1+lis_mem2(nums,curr-1,curr,n,dp);
            int notTake=lis_mem2(nums,curr-1,prev,n,dp);
            return dp[curr+1][prev]=max(take,notTake);
            
        }
        return dp[curr+1][prev]=lis_mem2(nums,curr-1,prev,n,dp);
    }
    
    int lis_dp2(vector<int> &nums, int n){
        //curr goes from n-1 to -1
        //prev goes from n to 0
        // 0 0 0 0 0 //curr is -1 and prev goes from 0 to n
        // 0 0 0 0 0 //curr is 0 and prev goes from 1 to n
        // 0 0 0 0 0
        //dp[curr+1][prev]
        //-1 0 1 2 3
        //when curr is -1, initialised to 0.
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int curr=0;curr<n;curr++){
            for(int prev=curr+1;prev<=n;prev++){
                //take not take
               // cout<<curr<<' '<<prev<<endl;
                if(prev==n||nums[curr]<nums[prev]){
                    int take=1+dp[curr-1+1][curr];
                    int notTake=dp[curr-1+1][prev];
                    dp[curr+1][prev]=max(take,notTake);
                }
                else
                    dp[curr+1][prev]=dp[curr][prev];
            }
        }
        
        return dp[n][n];
    }*/
    
    //space optimitisation
    //binary search
    int lis_bin(vector<int>& arr){
        int n=arr.size();
        int i=1;
        vector<int> seq;
        seq.push_back(arr[0]);
        int k=1;
        while(i<n){
            if(arr[i]>seq[k-1]){
                seq.push_back(arr[i]);
                k++;
            }
            else{
                vector<int>::iterator lower=lower_bound(seq.begin(),seq.end(),arr[i]);
                if(lower==seq.end()){
                    seq.push_back(arr[i]);
                    k++;
                }
                else{
                    seq[lower-seq.begin()]=arr[i];
                }
            }
            i++;
        }
        return k;
    }
    
    
public:
    int lengthOfLIS(vector<int>& nums) {
        //return lis_rec(nums,0,-1,n);
        //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        //return lis_dp2(nums,n);
        return lis_bin(nums);
    }
};