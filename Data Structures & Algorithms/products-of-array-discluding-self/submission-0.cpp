class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixArray(nums.size());
        vector<int> suffixArray(nums.size());

        for(int i = 0 ; i < nums.size() ; i++) {
            if(i == 0) {
                prefixArray[i] = nums[i];
            }
            else {
                prefixArray[i] = prefixArray[i-1] * nums[i];
            }
        }

        for(int i = nums.size() - 1 ; i >= 0 ; i--) {
            if (i == nums.size() - 1) {
                suffixArray[i] = nums[nums.size() - 1];
            }
            else {
                suffixArray[i] = suffixArray[i + 1] * nums[i];
            }
        }

        vector<int> result(nums.size());
        for (int i = 0 ; i < nums.size() ; i++) {
            if (i == 0) {
                result[i] = suffixArray[i + 1];
            }
            else if (i == nums.size() - 1) {
                result[i] = prefixArray[i - 1];
            }
            else {
                result[i] = prefixArray[i - 1] * suffixArray[i + 1];
            }
        }

        return result;

    }
};
