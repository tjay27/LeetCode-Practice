class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        int str=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                k++;
                nums[str]=nums[i+1];
                str++;
            }
        }
        return k;
    }
};