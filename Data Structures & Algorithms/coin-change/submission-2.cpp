class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1 ; i < dp.size() ; i++) {
            for (auto coin : coins) {
                
                if (i - coin < 0) {             // coin is greater than the value of the dp[i]
                    continue;
                }

              
                int numberOfCoin = dp[i - coin] + 1;

                dp[i] = min(numberOfCoin, dp[i]);
            }
        }

        return dp.back() == amount + 1 ? -1 : dp.back();

    }
};
