class Solution {
    int maxenv(vector<vector<int>> &envelopes,int ei, int previ,int n){
        //recursive approach
        //base case
        if(ei==-1)
            return 0;
        //notTake
        int notTake=maxenv(envelopes,ei-1,previ,n);
        //take
        //areas compare
        //take
        if(previ==n||(envelopes[ei][1]<envelopes[previ][1])){
            int take=1+maxenv(envelopes,ei-1,ei,n);
            return max(take,notTake);
        }
        return notTake;
    }
    // int findLowerBound(vector<vector<int>> envelopes,int si,int ei, int target){
    //     while(si<=ei){
    //         int mid=(si+ei)/2;
    //         if(envelopes[mid][1]==target)
    //             return mid;
    //         if(envelopes[mid][1]<target){
    //             si=mid+1;
    //         }
    //         else{
    //             ei=mid-1;   
    //         }
    //     }
    //     return si;
    // }
    int lis_bin(vector<vector<int>> &envelopes){
        //lower bound
        //binary search wle m mere paas prev kya tha uska track nhi rehta, so i can't do if prev wle se              //unequal wla approach, so to avoid that we just sort the width in reverse
        vector<int> lis;
        int n=envelopes.size();
        for(int i=0;i<n;i++){
            int idx=lower_bound(lis.begin(),lis.end(),envelopes[i][1])-lis.begin();    
            if(idx==lis.size())
                lis.push_back(envelopes[i][1]);
            lis[idx]=(envelopes[i][1]);
                
        }
        return lis.size();
        
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        /*sort(envelopes.begin(),envelopes.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]*a[1]!=b[0]*b[1])
                return a[0]*a[1]<b[0]*b[1];
            else{
                return a[0]<b[0];
            }
        });  
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]!=b[0])
                return a[0]<b[0];
            return a[1]<b[1];
        });  */
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]!=b[0])
                return a[0]<b[0];
            return a[1]>b[1];
        });
        int n=envelopes.size();
        return lis_bin(envelopes);
    }
};


 