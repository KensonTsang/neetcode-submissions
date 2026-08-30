class Solution {
public:
    string longestPalindrome(string s) {
        int startIndex = 0;
        int maxLength = 0;
        int n = s.size();

        vector<vector<bool>> dp (n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0 ; i--) {
            for (int j = i ; j < n ; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || dp[i + 1][j - 1])) {
                    
                    // j - i = 0 (指向同一個)
                    // j - i = 1 (兩個 character)
                    // j - i = 2 (3個 character)

                    dp[i][j] = true;
                    if ((j - i + 1) >= maxLength) {
                        startIndex = i;
                        maxLength = (j - i + 1);
                    }
                        
                }

            }
        }

        return s.substr(startIndex, maxLength);
    }
};
