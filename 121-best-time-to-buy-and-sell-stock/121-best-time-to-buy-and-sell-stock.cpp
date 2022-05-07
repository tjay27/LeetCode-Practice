class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0];
        int maxP=0;
        
        for(int i=1;i<n;i++){
            if(prices[i]>buy&&prices[i]-buy>maxP){
                maxP=prices[i]-buy;
            }
            else if(prices[i]<buy){
                buy=prices[i];
            }
        }
        return maxP;
    }
};