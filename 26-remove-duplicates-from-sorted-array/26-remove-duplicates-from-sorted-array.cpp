class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr=1;
        int i=1;
        int n=nums.size();
        while(i<n){
            if(nums[i]!=nums[i-1]){
                nums[ptr]=nums[i];
                ptr++;
            }
            i++;
        }
        return ptr;
    }
};