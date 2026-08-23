class Solution {
public:

    unordered_map<int, vector<int>> preMap;
    vector<int> result;
    
    unordered_set<int> visiting;
    unordered_set<int> visited;

    bool dfs(int curIndex) {
        
        if (visiting.count(curIndex)) {         // cycle 
            return false;
        }

        if (visited.count(curIndex)) {          // already processed
            return true;
        }

        visiting.insert(curIndex);

        for (auto& preIndex : preMap[curIndex]) {
            if (!dfs(preIndex)) {
                return false;
            }
        }

        visiting.erase(curIndex);
        visited.insert(curIndex);


        result.push_back(curIndex);
        preMap[curIndex].clear();


        return true;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        for (int i = 0 ; i < numCourses ; i++) {
            preMap[i] = {};
        }

        for (auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }
        
        for (int i = 0 ; i < numCourses ; i++) {
            if(!dfs(i)) {
                return {};
            }
        }


        return result;


    }
};
