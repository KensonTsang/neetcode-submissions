class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp (s.size() + 1, 0);
        dp[0] = 1;

        for (int i = 1 ; i < dp.size() ; i++) {
            
            // 1-9
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            if (i >= 2) {
                int num = (s[i - 2] - '0') * 10 +
                           s[i - 1] - '0';

                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i - 2];
                }

            }

        }


        return dp.back();
    }
};
