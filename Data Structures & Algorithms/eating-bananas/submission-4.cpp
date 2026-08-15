class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxPiles = 0;
        for (const auto& pile : piles) {
            maxPiles = max(pile, maxPiles);
        }

        int l = 1;
        int r = maxPiles;

        int result = INT_MAX;
        while (l <= r) {
            int mid =  l + (r - l) / 2;

            int k = 0;
            for (int i = 0 ; i < piles.size() ; ++i) {
                k += (piles[i] + (mid - 1)) / mid;
            }

            if (k <= h) {
                result = min(mid, result);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }

        }

        return result;
        


    }
};
