class Solution {
public:
   /* #include<unordered_map>
    int subarraySum(vector<int>& nums, int k) {
        //sub array sum equals k
        unordered_map<int,int> mp; // sum, freq
        
        mp[0]++;
        int cum_sum=0;//cumulative sum
        int subArrSumk=0;
        for(int i=0;i<nums.size();i++){
            cum_sum+=nums[i];
            if(mp.find(cum_sum-k)!=mp.end()){
                subArrSumk+=mp[cum_sum-k];
            }
            mp[cum_sum]++;
        }
        
        return subArrSumk;
        
    }*/
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
//PLEASE UPVOTE IF YOU LIKE MY SOLUTION  :)
    }
    
};