class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        //reverse the entire array
        reverse(nums.begin(), nums.end());
        //reverse the 2 parts seperately
        //rev part 1
        reverse(nums.begin(),nums.begin()+k);
        // //rev part 2
        reverse(nums.begin()+k, nums.end());
        return ;
        
    }
};