class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int prefixSum = 0;
        int result = 0;

        for (int r = 0 ; r < nums.size() ; r++) {
            
            prefixSum += nums[r];

            while (prefixSum >= target) {

                result = (result == 0)? (r - l + 1) : min(result, (r - l + 1));

                prefixSum -= nums[l];
                l++;

                if (l > r) {
                    return result;
                }

            }
        }

        return result;  
    }
};