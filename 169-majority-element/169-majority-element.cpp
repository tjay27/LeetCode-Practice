class Solution {
public:
    #include<unordered_map>
    //time-o(n), space-o(n)
    int majorityElement(vector<int>& arr) {
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
        int n=arr.size();
        int count=1;
        int maj=arr[0];
        for(int i=1;i<n;i++){
            if(maj==arr[i])
                count++;
            else
                count--;
            if(count==0){
                maj=arr[i];
                count++;}
        }
        
        return maj;
        int freq=0;
        for(int i=1;i<n;i++){
            if(arr[i]==maj)
                freq++;
        }
        //cout<<int(n/2);
        //return maj;
        return freq>int(n/2)?maj:0;
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