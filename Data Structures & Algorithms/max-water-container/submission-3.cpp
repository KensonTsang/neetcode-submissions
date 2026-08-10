class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int result = 0;
        while (l < r) {
            int lHeight = heights[l];
            int rHeight = heights[r];

            int minHeight = min(lHeight, rHeight);
            int distance = r - l;

            result = max(minHeight * distance, result);

            if (lHeight > rHeight) {
                r--;
            }
            else {
                l++;
            }
        }

        return result;
    }
};
