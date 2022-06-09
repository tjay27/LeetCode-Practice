class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        vector<int> ans;
        
        while(i<j){
            //cout<<nums[i]<<' '<<nums[j]<<endl;
            if(target==nums[i]+nums[j]){
                vector<int> v;
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(target>nums[i]+nums[j]){
                i++;
                while(nums[i]==nums[i-1])
                    i++;
            }
            else if(target<nums[i]+nums[j]){
                j--;
                while(nums[j]==nums[j+1])
                    j--;
            }
        }
        return ans;
    }
};