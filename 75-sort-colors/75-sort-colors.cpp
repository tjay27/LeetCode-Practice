class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k=0;
        int n0=0;
        int n2=nums.size()-1;
        
        while(k<=n2){
            if(nums[k]==1)
                k++;
            else if(nums[k]==2){
                int t=nums[k];
                nums[k]=nums[n2];
                nums[n2]=t;
                //k++;
                n2--;
            }
            else{
                int t=nums[k];
                nums[k]=nums[n0];
                nums[n0]=t;
                k++;
                n0++;
            }
        }
        return ;
    }
};