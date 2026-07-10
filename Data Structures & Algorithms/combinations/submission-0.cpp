class Solution {
public:

    void dfs(vector<int>& combs, int i, int n, int k, vector<vector<int>>& result) {
        if (combs.size() >= k) {
            result.push_back(combs);
            return;
        }

        if (i > n) {
            return;
        }

        combs.push_back(i);

        dfs(combs, i + 1, n, k, result);

        combs.pop_back();

        dfs(combs, i + 1, n, k, result);


    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result{};
        vector<int> combs{};
        dfs(combs, 1, n, k, result);
        return result;

    }
};