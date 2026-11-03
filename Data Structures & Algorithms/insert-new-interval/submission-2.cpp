class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> result{};
        int i = 0;

        // 1. insert the org intervals if the newInterval[0] is larger then intervals[1] (no overlap)
        while( i < intervals.size() && newInterval[0] > intervals[i][1]) {
            result.push_back(intervals[i]);
            i++;
        }

        // 2. handle overlap ()
        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        result.push_back(newInterval);

        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;

    }
};
