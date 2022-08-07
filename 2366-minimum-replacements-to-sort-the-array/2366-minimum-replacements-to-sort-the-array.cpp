class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int prev=nums[n-1];
        long long ans=0;
        int curr=0;
        for(int i=n-2;i>=0;i--){
            curr=nums[i];
            if(curr<=prev){
                prev=curr;
                continue;
                
            }
            else{
                if(curr%prev==0){
                    ans+=curr/prev - 1;
                }
                else{
                    ans+=curr/prev;
                    int numOfPieces=curr/prev + 1;
                    prev=curr/numOfPieces;
                }
                
            }
        }
        return ans;
    }
};