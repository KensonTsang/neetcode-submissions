class Solution {
public:

    unordered_map<int, vector<int>> map_;
    unordered_set<int> visited_;

    bool dfs(int index, int parent) {

        if (visited_.count(index)) {
            return false;
        }


        visited_.insert(index);

        for (auto i : map_[index]) {

            if (i == parent) {
                continue;
            }

            if (!dfs(i, index)) {
                return false;
            }
        }


        return true;

    }


    bool validTree(int n, vector<vector<int>>& edges) {

        if (n <= 0) {
            return false;
        }
        
        map_ = {};
        visited_ = {};

        for (int i = 0 ; i < n ; i++) {
            map_[i] = {};
        }

        for (auto& v : edges) {
            map_[v[0]].push_back(v[1]);
            map_[v[1]].push_back(v[0]);
        }


        if (!dfs(0, -1)) {
            return false;
        }

        return visited_.size() == n;

    }
};
