class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice=prices[0];
        int n=prices.size();
        int totalProfit=0;
        
        int maxProfit=0;
        
        for(int i=1;i<n;i++){
            if(prices[i]<prices[i-1]){
                buyPrice=prices[i];
                totalProfit+=maxProfit;
                maxProfit=0;
            }
            else if(prices[i]>buyPrice){
                int profit=prices[i]-buyPrice;
                if(profit>maxProfit)
                    maxProfit=profit;
            }
            
        }
        totalProfit+=maxProfit;
        
        return totalProfit;
        
        
    }
};