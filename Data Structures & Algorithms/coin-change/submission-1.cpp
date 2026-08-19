class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp (amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1 ; i < dp.size() ; i++) {
            for (int coin : coins) {

                int target = i - coin;
                if (target < 0) {
                    continue;
                }

                dp[i] = min(dp[target] + 1, dp[i]);

            }
        }
    
        
        return dp[amount] == amount + 1 ? -1 : dp[amount];

    }
};
