class Solution {
public:

    void dfs(vector<int>& nums, int i, vector<vector<int>>& result, vector<int>& subset) {

        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1, result, subset);
        subset.pop_back();

        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        dfs(nums, i + 1, result, subset);                

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> result{};

        vector<int> subset{};

        sort(nums.begin(), nums.end());

        dfs(nums, 0, result, subset);

        return result;
    }
};
