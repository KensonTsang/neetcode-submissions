class Solution {
public:

    unordered_map<int, vector<int>> map_;
    unordered_set<int> visiting_;


    bool dfs(int num) {

        if (visiting_.count(num)) {
            return false;
        }

        if (map_[num].size() <= 0) {
            return true;
        }

        visiting_.insert(num);
        for (const auto& prereq : map_[num]) {
            if (!dfs(prereq)) {
                return false;
            }
        }

        visiting_.erase(num);
        map_[num].clear();

        return true;

    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for (int i = 0 ; i < numCourses ; ++i) {
            map_[i] = {};
        }
        
        for (auto& v : prerequisites) {
            map_[v[0]].push_back(v[1]);
        }


        for (int i = 0 ; i < numCourses ; ++i) {
            if (!dfs(i)) {
                return false;
            }
        }

        return true;

    }
};
