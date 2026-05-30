class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int result = 0;
        int arr[26] = {0};
        int mostFreqIndex = 0;

        for(int r = 0; r < s.size() ; r++) {
            int cIndex = s[r] - 'A';            
            arr[cIndex]++;            
            mostFreqIndex = max(mostFreqIndex, arr[cIndex]);    
            // mostFreq no need to reset everytime

            // (r - l + 1) - mostFreqIndex; <-- is not match number count
            while( (r - l + 1) - mostFreqIndex > k ) {
                arr[s[l] - 'A']--;
                l++;      
            }

            result = max(result, r - l + 1);

        }

        return result;

    }
};
