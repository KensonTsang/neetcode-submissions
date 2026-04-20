class Solution {
public:

    bool validParlindrome(string& s, int l, int r) {

        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        
        int l = 0;
        int r = s.size() - 1;


        while (l < r) {
        
            if (s[l] != s[r]) {
                return validParlindrome(s, l + 1, r) || validParlindrome(s, l, r - 1);
            }

            l++;
            r--;
        }



        return true;

    }
};