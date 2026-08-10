class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        

        while (l <= r) {
            char l_c = s[l];
            char r_c = s[r];

            if (!isalnum(l_c)) {
                l++;
                continue;
            }

            if (!isalnum(r_c)) {
                r--;
                continue;
            }

            l_c = tolower(l_c);
            r_c = tolower(r_c);

            if (l_c != r_c) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
