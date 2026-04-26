class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for (const auto& p : piles ) {
            r = max(r, p);
        }


        while (l < r) {
            int m = l + ((r - l) / 2);
            
            int hours = 0;
            for (int i = 0 ; i < piles.size() ; i++) {
                hours += (piles[i] + m - 1) / m;
            }


            if (hours <= h) {
                r = m;
            }
            else if (hours > h) {
                l = m + 1;                
            }
        }
        

        return l;
    }
};
