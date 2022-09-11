class Solution {
    #define lli long long int 
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        //sort on the basis of efficiency - decreasing order
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({speed[i],efficiency[i]});
        }
       
        sort(v.begin(),v.end(),[](pair<int,int>& a, pair<int,int>& b){
            return a.second>b.second;
        });
        
        
        lli topKsum=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        lli perf=INT_MIN;
        
        for(int i=0;i<n;i++){
            lli min_eff=v[i].second;
            lli sumSpeed= (lli)v[i].first + topKsum;
            
            perf=max(sumSpeed*min_eff,perf);
            pq.push(v[i].first);
            topKsum+=(lli)v[i].first;
            //updating top K-1 sum
            if(pq.size()>k-1){
                topKsum-=(lli)pq.top();
                pq.pop();
            }
        }
        
        return perf%1000000007;
    }
};