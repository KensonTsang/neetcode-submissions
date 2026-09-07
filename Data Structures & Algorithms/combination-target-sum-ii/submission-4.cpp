class Solution {
public:

    void dfs(vector<int>& candidates, int target, int i, vector<vector<int>>& result, vector<int>& comb) {

        if (target == 0) {
            result.push_back(comb);
            return;
        }

        if (i >= candidates.size() || target < 0) {
            return;
        }

        comb.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i + 1, result, comb);

        
        while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
            i++;
        }

        comb.pop_back();
        dfs(candidates, target, i + 1, result, comb);

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result{};
        vector<int> comb;

        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, 0, result, comb);

        return result;

    }
};
