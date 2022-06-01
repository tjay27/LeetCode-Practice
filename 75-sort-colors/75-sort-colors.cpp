class Solution {
    void swap(int &x,int &y){
        int temp=x;
        x=y;
        y=temp;
        return;
    }
public:
    void sortColors(vector<int>& nums) {
        //SORT O,1,2
        
        //Dutch national flag
        
        //low, med, high
        
        //med traverses
        int n=nums.size();
        
        int low=0;
        int med=0;
        int high=n-1;
        
        while(med<=high){
            if(nums[med]==0){
                swap(nums[low],nums[med]);
                low++;
                med++;
            }
            else if(nums[med]==1){
                med++;
            }
            else if(nums[med]==2){
                swap(nums[med],nums[high]);
                high--;
            }
        }
        
        return ;
        
    }
};