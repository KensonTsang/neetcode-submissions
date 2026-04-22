class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(char c : t) {
            need[c]++;
        }

        int valid = 0;
        int l = 0;
        
        int start = 0;
        int minLen = INT_MAX;

        for(int r = 0 ; r < s.size() ; r++) {
            char c = s[r];            

            if (need.count(c)) {
                window[c]++;
                if(window[c] == need[c]) {
                    valid++;
                }
            }


            while(valid == need.size()) {            
                if (r - l + 1 < minLen) {
                    start = l;
                    minLen = r - l + 1;
                }

                char d = s[l];
                l++;

                if (need.count(d)) {
                    
                    if (need[d] == window[d]) {
                        valid--;
                    }
                    window[d]--;
                }


            }


        }


        return minLen == INT_MAX ? "" : s.substr(start, minLen);


    }
};
