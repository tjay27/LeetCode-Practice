class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        /*//O(n^2)
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                maxSum=max(maxSum,sum);
            }
        }
        return maxSum;*/
        int csum=0;
        for(int i=0;i<n;i++){
            csum+=nums[i];
            maxSum=max(csum,maxSum);
            if(csum<0){
                csum=0;
            }
        }
        return maxSum;
    }
};