class Solution {
public:

    unordered_map<int, vector<int>> map_;
    unordered_set<int> visited_;

    void dfs(int i) {
        
        if (visited_.count(i)) {
            return;
        }

        visited_.insert(i);

        for (auto i : map_[i]) {
            dfs(i);
        }

    }


    int countComponents(int n, vector<vector<int>>& edges) {

        for (int i = 0 ; i < n ; i++) {
            map_[i] = {};
        }


        for (auto& v : edges) {
            map_[v[0]].push_back(v[1]);
            map_[v[1]].push_back(v[0]);            
        }

        int result = 0;

        for (int i = 0 ; i < n ; i++) {
            if (visited_.count(i) <= 0) {   // not existed means it is the starting point of the graph
                result++;
                dfs(i);
            }
        }

        return result;

    }
};
