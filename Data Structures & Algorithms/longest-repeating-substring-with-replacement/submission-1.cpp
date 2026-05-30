class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int result = 0;
        int arr[26] = {0};

        for(int r = 0; r < s.size() ; r++) {
            int cIndex = s[r] - 'A';            
            arr[cIndex]++;

            int mostFreqIndex = 0;
            for (int i = 0 ; i < 26 ; i++) {
                mostFreqIndex = max(mostFreqIndex, arr[i]);
            }

            // (r - l + 1) - mostFreqIndex; <-- is not match number count
            while( (r - l + 1) - mostFreqIndex > k ) {
                arr[s[l] - 'A']--;
                l++;

                mostFreqIndex = 0;
                for (int i = 0 ; i < 26 ; i++) {
                    mostFreqIndex = max(mostFreqIndex, arr[i]);
                }                
            }

            result = max(result, r - l + 1);

        }

        return result;

    }
};
