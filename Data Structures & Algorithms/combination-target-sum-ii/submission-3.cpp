class Solution {
public:

    void dfs(const vector<int>& candidates, int target, vector<int>& comb, vector<vector<int>>& result, int i) {        

        if (i >= candidates.size() || target <= 0) {
            if (target == 0) {
                result.push_back(comb);
            }
            return;
        }

        comb.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], comb, result, i + 1);
        
        comb.pop_back();

        while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
            i++;
        }

        dfs(candidates, target, comb, result, i + 1);     

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result{};
        vector<int> comb{};

        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, comb, result, 0);

        return result;

    }
};
