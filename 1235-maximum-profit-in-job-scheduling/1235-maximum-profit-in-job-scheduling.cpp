// class Solution {
//     //in lis you are going from 0 to j for finding the value
//     int maxProfit(vector<vector<int>> &intervals){
//         //lis format
//         //dp[i] stores the max profit of all those intervals which gives the max profit while the           //interval starting at i is present.
//         int n=intervals.size();
//         int omax=0;
//         vector<int> dp(n);
//         dp[0]=intervals[0][2]; //stored the profit
//         for(int i=0;i<n;i++){
//             int maxProfit=0;
//             int maxProfit=maxPtillNow_binsearch();
//             for(int j=0;j<i;j++){
//                 if(intervals[j][1]<=intervals[i][0]){
//                     if(dp[j]>maxProfit)
//                         maxProfit=dp[j];
//                 }
//             }
//             dp[i]=maxProfit+intervals[i][2];
//             omax=max(dp[i],omax);
//         }
//         return omax;
//     }
//     int maxProfit_bins(vector<vector<int>> &intervals){
//         int n=intervals.size();
//         //find profit maximiser
//         //usme length maximise krna tha, yaha profit ko krna hai.
//     }
//     int findNext(vector<vector<int>> intervals, int i, vector<int> &dp) {
//         int lo = 0;
//         int hi = i;
//         while(lo < hi) {
//             int mid = lo + (hi - lo)/2;
//             if(jobs[mid][0] <= jobs[i][1]) {
//                 if(jobs[mid-1][0] >= jobs[i][1])
//                     hi = mid - 1;
//                 else 
//                     return mid;
//             } else {
//                 lo = mid + 1;
//             }
//         }
        
//         return -1;
//     }
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         vector<vector<int>> intervals;
//         int n=startTime.size();
//         for(int i=0;i<n;i++){
//             intervals.push_back(vector<int>{startTime[i],endTime[i],profit[i]});
//         }    
//         sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
//             if(a[0]!=b[0])
//                 return a[0]<b[0];
//             if(a[1]!=b[1])
//                 return a[1]>b[1];
//             return a[2]<b[2];
//         });
//         return maxProfit(intervals);
//     }
// };
class Solution {
public:
    static bool mycomp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
    
        return a.second.first<b.second.first;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<pair<int,pair<int,int>>>v;
        if(startTime.size()==0)return 0;
        for(int i=0;i<startTime.size();i++){
            v.push_back({startTime[i],{endTime[i],profit[i]}});
        }
      
        sort(v.begin(),v.end(),mycomp);
        int m=v[0].second.second;
        vector<int>arr(profit.size(),0);
        arr[0]=m;
        for(int i=1;i<profit.size();i++){
            arr[i]=max(arr[i-1],v[i].second.second);
            m=max(m,arr[i]);
           for(int j=i-1;j>=0;j--){
              if(v[i].first>=v[j].second.first){
                    arr[i]= max(arr[i],arr[j]+v[i].second.second);
                  m=max(m,arr[i]);
                    break;
                }
           }
            }
        
                        return m;
        
    }
};