
class Solution {
public:
    #include<unordered_map>
    #include<queue>
     class cmp{
         public:
         bool operator()(pair<int,int> p1,pair<int,int> p2){
            return p1.second<p2.second?true:false;
         }
     };
     
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(auto i:mp){
            pq.push(i);
            //pq.erase(i.first);
        }
        
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};