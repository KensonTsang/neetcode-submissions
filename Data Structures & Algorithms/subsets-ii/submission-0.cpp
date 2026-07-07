class Solution {
public:

    void dfs(const vector<int>& nums, int i, vector<int>& subsets, vector<vector<int>>& result) {
        if (i >= nums.size()) {
            result.push_back(subsets);
            return;
        }

        subsets.push_back(nums[i]);
        dfs(nums, i + 1, subsets, result);

        subsets.pop_back();
        while ( i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        dfs(nums, i + 1, subsets, result);

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result{};
        vector<int> subsets{};

        sort(nums.begin(), nums.end());

        dfs(nums, 0, subsets, result);

        return result;
    }
};
