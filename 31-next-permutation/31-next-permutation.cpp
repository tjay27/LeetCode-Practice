class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        for(int j=nums.size()-1;j>0;j--){
            if(nums[j-1]<nums[j]){
                idx=j-1;
                break;
            }
        }
        if(idx==-1)
            reverse(nums.begin(),nums.end());
        else{
            int i=nums.size()-1;
            int idx2=0;
            while(i>idx){
                if(nums[i]>nums[idx]){
                    idx2=i;
                    break;    
                }
                i--;
            }
            int temp=nums[idx];
            nums[idx]=nums[idx2];
            nums[idx2]=temp;
            sort(nums.begin()+idx+1,nums.end());
        }
        return ;
        
    }
};