class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size()<3)
            return 0;
        int possible=0;
        int i=0;
        
        while(i<nums.size()-2){
            int d=nums[i+1]-nums[i];
            int j=i+1;
            int len=2;
            while(j<nums.size()-1){
                if(nums[j+1]-nums[j]==d){
                    len++;
                    j++;
                    i++;
                }
                else{
                    d=nums[j+1]-nums[j];
                    i++;
                    j++;
                    break;
                }
            }
            if(len>=3){
                int k=3;
                while(k<=len){
                    possible+= len-k+1;
                    k++;
                }
            }
        
        }
        return possible;
    }
};