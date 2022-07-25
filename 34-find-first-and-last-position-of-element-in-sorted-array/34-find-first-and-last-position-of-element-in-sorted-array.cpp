class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //5 7 7 8 8 10
       // for lower range - just find upperbound
       // for upper range - find upperbound of target+1
        vector<int> ans(2,-1);
        //for lower
        vector<int>::iterator lower=lower_bound(nums.begin(),nums.end(),target);    //target or greater than that
        if(lower==nums.end()||*lower!=target)   //if number doesn't exist or returned greater instead.
            return ans;
        else 
            ans[0]=lower-nums.begin();
        
        vector<int>::iterator upper=upper_bound(nums.begin(),nums.end(),target);  //position of number greater than target
        ans[1]=upper-nums.begin()-1;
        return ans;
    }
};