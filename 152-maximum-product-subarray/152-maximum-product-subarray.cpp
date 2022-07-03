class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //BRUTE FORCE-o(n^2),o(1)
        /*int n=nums.size();
        int maxProduct=nums[0];
        for(int i=0;i<n;i++){
            int product=1;
            for(int j=i;j<n;j++){
                product*=nums[j];
                if(product>maxProduct){
                    maxProduct=product;
                }
            }
        }
        
        
        
        return maxProduct;
    */
        //kadane like approach
        
        //pepcoding approach
        //claim - ans lies in either first half or back half.
        //will find the max from both sides.
        //return the max of them.
        
        int n=nums.size();
        int ans1=INT_MIN;
        int ans2=INT_MIN;
        int cprod=1;
        
        for(int i=0;i<n;i++){
            cprod*=nums[i];
            ans1=max(cprod,ans1);
            if(cprod==0)
                cprod=1;
        }
        cprod=1;
        for(int i=n-1;i>=0;i--){
            cprod*=nums[i];
            ans2=max(cprod,ans2);
            if(cprod==0)
                cprod=1;
        }
        
        
        return max(ans1,ans2);
        
        
        
        
        
        
    }
};