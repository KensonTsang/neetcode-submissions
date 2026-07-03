class Solution {
public:

    void dfs (const vector<int>& nums, vector<int>& combs, int target, int i, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(combs);
        }
        if (target <= 0 || i >= nums.size()) {
            return;
        }

        combs.push_back(nums[i]);
        dfs(nums, combs, target - nums[i], i, result);
        combs.pop_back();
        dfs(nums, combs, target, i + 1, result);

    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result{};
        vector<int> combs;
        dfs(nums, combs, target, 0, result);
        return result;
    }
};
