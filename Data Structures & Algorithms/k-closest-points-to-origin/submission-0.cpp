class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > minHeap{};

        for (auto& v : points) {
            int length = abs(v[0] * v[0] + v[1] * v[1]);
            minHeap.push({length, v});
        }

        vector<vector<int>> result;
        for (int i = 0 ; i < k ; i++) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;

    }
};
