class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int  n =prices.size();
    vector<int>buy(n);
    buy[0]=prices[0];
    for(int i =1;i<prices.size();i++){
        buy[i]=min(prices[i],buy[i-1]);
    }
    int profit =0;
    for(int i=0;i<prices.size();i++){
      int  maxprofit= prices[i]-buy[i];
      profit=max(profit,maxprofit);
    }
      
    return profit;
    }
};