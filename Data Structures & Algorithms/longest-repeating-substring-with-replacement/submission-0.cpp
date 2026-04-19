class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int result = 0;
        int arr[26] = {0};


        for (int r = 0 ; r < s.size() ; r++) {
            int cIndex = s[r] - 'A';
            arr[cIndex]++;

            int maxCharNum = 0;
            for (int i = 0 ; i < 26 ; i++) {
                maxCharNum = max(maxCharNum, arr[i]);
            }

            while ((r - l + 1) - maxCharNum > k) {
                arr[s[l] - 'A']--;
                l++;

                maxCharNum = 0;
                for (int i = 0 ; i < 26 ; i++) {
                    maxCharNum = max(maxCharNum, arr[i]);
                }
            }

            result = max(result, r - l + 1);


        }


        return result;
    }
};
