class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result{};
        result.push_back(intervals[0]);

        for (int i = 1 ; i < intervals.size() ; ++i) {
            vector<int>& cur  = intervals[i];
            vector<int>& prev = result.back();

            if (cur[0] <= prev[1]) {
                prev[1] = max(prev[1], cur[1]);     // merge
            }
            else {
                result.push_back(cur);
            }
        }

        return result;
        

    }
};
