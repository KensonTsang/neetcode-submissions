class Solution {
public:
    int trap(vector<int>& height) {
        int peakIndex = 0;
        for(size_t i = 0 ; i < height.size() ; i++) {            
            peakIndex = height[i] > height[peakIndex] ? i : peakIndex;
        }

        int water = 0;

        // left
        int i = 0;
        int leftMostIndex = i;
        while(i < peakIndex) {
            if (height[i] < height[leftMostIndex]) {
                water += height[leftMostIndex] - height[i];
            }
            else {
                leftMostIndex = i;
            }
            i++;
        }

        // right
        i = height.size() - 1;
        int rightMostIndex = i;
        while (i > peakIndex) {
            if (height[i] < height[rightMostIndex]) {
                water += height[rightMostIndex] - height[i];
            }
            else {
                rightMostIndex = i;
            }
            i--;
        }

        return water;
    }
};
