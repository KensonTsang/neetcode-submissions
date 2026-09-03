class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxProduct = nums[0];
        int minProduct = nums[0];

        int result = maxProduct;

        for (int i = 1 ; i < nums.size() ; i++) {
            int num = nums[i];

            int curMax = max({ num, maxProduct * num, minProduct * num});
            int curMin = min({ num, minProduct * num, maxProduct * num});

            maxProduct = curMax;
            minProduct = curMin;

            result = max(result, maxProduct);
        }


        return result;

    }
};
