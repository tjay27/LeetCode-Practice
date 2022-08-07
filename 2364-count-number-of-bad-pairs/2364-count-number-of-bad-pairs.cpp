class Solution {
    #include<unordered_map>
public:
    long long countBadPairs(vector<int>& a) {
        int n=a.size();
        //find all the good pairs
        long long totalValidPairs=0;
        unordered_map<long long, long long> mp;
        for(int i=0;i<n;i++){
            if(mp.find(i-a[i])!=mp.end())
                totalValidPairs+=mp[i-a[i]];
            mp[i-a[i]]++;
        }
        return (long)n*(n-1)/2 - totalValidPairs;
    }
};