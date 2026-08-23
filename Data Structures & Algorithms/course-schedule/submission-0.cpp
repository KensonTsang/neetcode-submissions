class Solution {
public:

    unordered_map<int, vector<int>> preMap{};
    unordered_set<int> visiting;

    bool dfs (int index) {

        if (visiting.find(index) != visiting.end()) {
            return false;
        }

        if (preMap[index].empty()) {
            return true;
        }

        visiting.insert(index);
        for (auto& preIndex : preMap[index]) {            
            if (!dfs(preIndex)) {
                return false;
            }
        }

        visiting.erase(index);
        preMap[index].clear();
        return true;

    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        for (int i = 0 ; i < numCourses ; i++) {
            preMap[i] = {};
        }

        for (const auto& prereq: prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0 ; i < numCourses ; i++) {
            if(!dfs(i)) {
                return false;
            }
        }


        return true;

    }
};
