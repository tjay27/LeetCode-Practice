class Solution {
public:
    #include<unordered_map>
    //time-o(n), space-o(n)
    int majorityElement(vector<int>& nums) {
      /*  int occReq=nums.size()/2;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxOcc=0;
        for(auto key:mp){
            if(key.second>occReq&&key.second>mp[maxOcc]){
                maxOcc=key.first;
            }
        }
        return maxOcc;*/
        
        //sorting time-o(nlogn), space-o(1)
        /*std::sort(nums.begin(),nums.end());
        return nums[nums.size()/2];*/
        
       //time-o(n), space-o(1), Moore's voting algo
        
        int count=0;//chances of it being a maj
        int maj=nums[0];
        for(int i=0;i<nums.size();i++){
            if(maj==nums[i])
                count++;
            else
                count--;
            if(count==0){
                maj=nums[i];
                count++;
            }
        }
        return maj;
        
        //find freq of maj and check if its greater than n/2
        /* not needed cuz given in que Maj element exists for sure
        for(int i=0;i<nums.size();i++){
            if(maj==nums[i])
                l++;
        }
        if(l>n/2)
            return maj;
        return 0;*/
    
    }

};