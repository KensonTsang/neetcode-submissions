class Solution {
public:

    void backtrack(vector<int>& perm, vector<int>& nums, vector<bool>& pick, vector<vector<int>>& result) {
        if (perm.size() == nums.size()) {
            result.push_back(perm);
            return;
        }

        for (int i = 0 ; i < nums.size(); i++) {
            if (!pick[i]) {
                perm.push_back(nums[i]);
                pick[i] = true;
                backtrack(perm, nums, pick, result);
                perm.pop_back();
                pick[i] = false;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result{};
        vector<bool> pick(nums.size(), false);
        vector<int> perm;
        backtrack(perm, nums, pick, result);
        return result;
    }
};
