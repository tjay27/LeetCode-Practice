class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        //int mid=0;//traverses
        while(mid<=high){
            if(nums[mid]==0){
                //swap
                int t=nums[low];
                nums[low]=nums[mid];
                nums[mid]=t;
                low++;
                mid++;
            }
            else if(nums[mid]==2){
                //swap
                int t=nums[mid];
                nums[mid]=nums[high];
                nums[high]=t;
                high--;
            }
            else{
                mid++;
            }
        }
        
        return;
    }
};