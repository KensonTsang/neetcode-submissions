class Solution {
public:

    bool canShip(const vector<int>& weights, int days, int cap) {
        int ships = 1, currCap = cap;
        for (int w : weights) {
            if (currCap - w < 0) {
                ships++;
                if (ships > days) {
                    return false;
                }
                currCap = cap;
            }
            currCap -= w;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0 ;
        int r = 0;

        for (int i = 0 ; i < weights.size(); i++) {
            l = max(l, weights[i]);
            r += weights[i];
        }

        int result = r;

        while (l <= r) {
            int cap = l + ((r - l) / 2);
            
            if (canShip(weights, days, cap)) {
                result = min(result, cap);
                r = cap - 1;
            }
            else {
                l = cap + 1;
            }
        }

        return result;
    }
};