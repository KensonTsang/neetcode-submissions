class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> mapping;

    TimeMap() {
        mapping = {};
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        if (mapping.count(key) <= 0) {
            return "";
        }

        auto& v = mapping[key];

        int l = 0;
        int r = v.size() - 1;

        // upper bound - 1;
        int ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;            

            if (timestamp >= v[m].first) {
                l = m + 1;
                ans = m;
            }
            else {
                r = m - 1;
            }
        }

        if (ans == -1)
            return "";

        return v[ans].second;


    }
};
