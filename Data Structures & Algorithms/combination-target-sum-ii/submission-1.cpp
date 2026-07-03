class Solution {
public:

    void dfs (const vector<int>& candidates, vector<int>& comb, int target, int i, vector<vector<int>>& result) {

        int sum = 0;
        for(auto num : comb) {
            sum += num;
        }

        if (sum >= target || i >= candidates.size()) {
            if (sum == target) {
                result.push_back(comb);
            }
            return;
        }

        comb.push_back(candidates[i]);
        dfs(candidates, comb, target, i + 1, result);

        comb.pop_back();

        while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
            i++;
        }

        dfs(candidates, comb, target, i + 1, result);

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result{};
        vector<int> comb{};

        sort(candidates.begin(), candidates.end());

        dfs(candidates, comb, target, 0, result);

        return result;

    }
};
