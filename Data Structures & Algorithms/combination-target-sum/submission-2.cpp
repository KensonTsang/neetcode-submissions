class Solution {
public:

    void dfs(vector<int>& nums, int target, int i, vector<vector<int>>& result, vector<int>& comb) {

        if (target == 0) {
            result.push_back(comb);
            return;
        }

        if (i >= nums.size() || target < 0) {
            return;
        }

        comb.push_back(nums[i]);
        dfs(nums, target - nums[i], i,result, comb);

        comb.pop_back();
        dfs(nums, target, i + 1,result, comb);


    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result{};
        vector<int> comb;

        dfs(nums, target, 0, result, comb);
        
        return result;

    }
};
