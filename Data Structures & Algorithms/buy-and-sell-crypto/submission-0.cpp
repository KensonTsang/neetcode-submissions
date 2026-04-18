class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;

        int maxProfit = 0;

        while (r < prices.size()) {

            if (prices[r] < prices[l]) {
                l = r;
            }
            else {
                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit, profit);
                r++;
            }
        }    


        return maxProfit;    



    }
};
