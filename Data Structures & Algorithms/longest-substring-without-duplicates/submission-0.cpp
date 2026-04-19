class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> map{};
        int l = 0;
        int maxLength = 0;

        for (int r = 0; r < s.size() ; r++) {
            char c = s[r];

            while (map.find(c) != map.end()) {
                map.erase(s[l]);
                l++;           
            }
            
            map.insert(c);
            maxLength = max((int)map.size(), maxLength);

        }

        return maxLength;

        
    }
};
