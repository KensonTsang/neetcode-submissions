class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> need{};
        unordered_map<char, int> window{};

        for(auto c : t) {
            need[c]++;
        }

        int l = 0;
        int valid = 0;

        int start = 0;
        int minLength = INT_MAX;

        for (size_t r = 0 ; r < s.size() ; r++) {
            char c = s[r];
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c]) {
                    valid++;
                }
            }


            while (valid == need.size()) {
                if ((r - l + 1) < minLength) {
                    start = l;
                    minLength = (r - l + 1);
                }

                char l_prev_c = s[l];
                l++;

                if (need.count(l_prev_c)) {
                    if (need[l_prev_c] == window[l_prev_c]) {
                        valid--;
                    }
                    window[l_prev_c]--;
                }
            }
            

        }


        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};
