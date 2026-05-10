class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> map{};

        int l = 0;
        int len = 0;
        
        for (auto r = 0 ; r < s.size() ; r++) {
            int c = s[r];

            while (map.count(c)) {
                map.erase(s[l]);
                l++;                
            }

            len = max(len, r - l + 1);
            map.insert(c);
        
        }
        
        return len;

        
    }
};
