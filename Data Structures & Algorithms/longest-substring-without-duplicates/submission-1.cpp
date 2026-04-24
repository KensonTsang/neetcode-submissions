class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> map{};

        int longest = 0;

        int l = 0;
        for (int r = 0 ; r < s.size() ; r++) {
            char c = s[r];
            while (map.count(c)) {
                map.erase(s[l]);
                l++;                
            }
            longest = max(longest, r - l + 1);                
            map.insert(c);
       }


        return longest;
        
    }
};
