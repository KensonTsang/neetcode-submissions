class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0;
        unordered_set<char> m{};    //map

        int maxLength = 0;

        for (int r = 0; r < s.size() ; ++r) {
            char c = s[r];            

            while (m.find(c) != m.end()) {
                m.erase(s[l]);
                l++;
            }
            m.insert(c);

            maxLength = max(maxLength, (int)m.size());
        }
        

        return maxLength;
        
    }
};
