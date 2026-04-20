class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int l = 0;
        int r = 0;

        string result;


        while(l < word1.size() || r < word2.size()) {

            if (l < word1.size()) {
                result += word1[l];
                l++;
            }

            if (r < word2.size()) {
                result += word2[r];
                r++;
            }

        }

        return result;

    }
};