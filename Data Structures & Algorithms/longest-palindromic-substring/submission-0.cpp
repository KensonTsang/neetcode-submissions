class Solution {
public: 

    void helper(int startL, int startR, string& maxString, string& s) {

        int l = startL;
        int r = startR;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            
            if (r - l + 1 > maxString.size()) {
                maxString = s.substr(l, r - l + 1);
            }
            
            l--;
            r++;
        }

    }

    string longestPalindrome(string s) {

       string maxString;

        for (int i = 0 ; i < s.size() ; i++) {
            
            // Odd
            helper(i, i, maxString, s);


            // Even
            helper(i, i+1, maxString, s);
        }


        return maxString;
    }
};
