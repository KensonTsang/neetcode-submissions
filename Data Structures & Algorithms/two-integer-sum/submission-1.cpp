class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> appearMapping{};

        for (auto i = 0 ; i < nums.size() ; i++) {
            int num = nums[i];
            int requiredNum = target - num;

            if (appearMapping.count(requiredNum)) {
                return {appearMapping[requiredNum], i};
            }

            appearMapping[num] = i;
        }

        return {};
    }
};
