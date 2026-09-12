class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> m{};
        int result = 0;
        int l = 0;

        for (int r = 0 ; r < s.size() ; r++) {
            char c = s[r];

            if (!m.count(c)) {      // not contain
                m.insert(c);
                result = max(r - l + 1, result);
                continue;
            }

            // contain repeating characters
            while (m.count(c) > 0) {
                m.erase(s[l]);
                l++;
            }
            
            m.insert(c);

        }

        return result;


    }
};
