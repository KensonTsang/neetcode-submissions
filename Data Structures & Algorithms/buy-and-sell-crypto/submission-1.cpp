class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int l = 0;        

        int maxProfit = 0;

        for (int r = 0 ; r < prices.size() ; ++r) {

            int profit = prices[r] - prices[l];
            maxProfit = max(profit, maxProfit);

            if (prices[r] < prices[l]) {
                l = r;
            }
        }

        return maxProfit;

    }
};
