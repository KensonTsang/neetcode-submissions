class Solution {
public:

    unordered_map<int, vector<int>> map_;
    unordered_set<int> visited_;

    bool dfs(int i, int parent) {

        if (visited_.count(i)) {
            return false;
        }                

        visited_.insert(i);

        for (auto connectedIndex : map_[i]) {

            if (connectedIndex == parent)
                continue;

            if(!dfs(connectedIndex, i)) {
                return false;
            }
        }
        

        return true;

    }


    bool validTree(int n, vector<vector<int>>& edges) {
    
        for (int i = 0 ; i < n ; i++) {
            map_[i] = {};            
        }


        for (auto& edge : edges) {
            map_[edge[0]].push_back(edge[1]);
            map_[edge[1]].push_back(edge[0]);
        }


        if(!dfs(0, -1)){
            return false;
        }


        return visited_.size() == n;

    }
};
