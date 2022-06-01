class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int buyPrice=prices[0];
        int n=prices.size();
        
        for(int i=1;i<n;i++){
            if(prices[i]>buyPrice){
                int profit=prices[i]-buyPrice;
                if(profit>maxProfit)
                    maxProfit=profit;
            }    
            else if(prices[i]<buyPrice){
                buyPrice=prices[i];
            }
        }
        
        return maxProfit;
        
    }
};