class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, vector<int>>> pq{};

        for (int i = 0 ; i < points.size() ; i++) {

            auto& v = points[i];
            int distance = abs(v[0] * v[0] + v[1] * v[1]);

            pq.push({distance, v});            
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> result{};


        while (pq.size() > 0) {
            auto p = pq.top();
            pq.pop();

            result.push_back(p.second);
        }

        return result;
    }
};
