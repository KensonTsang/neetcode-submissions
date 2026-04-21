class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        for (int i = 0 ; i < s1.size() ; i++) {
            int cIndex = s1[i] - 'a';
            s1Count[cIndex]++;
        }

        int left = 0;
        for (int right = 0; right < s2.size() ; right++) {
            int cIndex = s2[right] - 'a';
            s2Count[cIndex]++;

            if ((right - left + 1) > s1.size()) {
                int leftMostCharIndex = s2[left] - 'a';
                s2Count[leftMostCharIndex]--;
                left++;
            }

            if (s1Count == s2Count) {
                return true;
            }

        }


        return false;
    }
};
