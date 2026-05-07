class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;

        for (auto& p : piles) {
            r = max (r, p);
        }


        while (l < r) {
            int m = l + ((r - l) / 2);

            int hours = 0;
            for (auto& p : piles) {
                // hours += (p + m - 1) / m;
                if (p % m == 0)
                {
                    hours += p / m;
                }
                else 
                {
                    hours += (p / m) + 1;
                }
            }

            if (hours <= h) {
                r = m;
            }
            else {
                l = m + 1;
            }

        }

        return l;

    }
};
