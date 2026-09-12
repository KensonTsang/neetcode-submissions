class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int l = 0;        
        int maxProfit = 0;

        for (int r = 0 ; r < prices.size() ; r++) {

            maxProfit = max(prices[r] - prices[l], maxProfit);
            
            if (prices[r] < prices[l]) {
                l = r;
            }
        }

        return maxProfit;

    }
};
