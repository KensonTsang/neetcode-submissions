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
        int r = v.size();

        // upper bound - 1;
        while (l < r) {
            int m = l + (r - l) / 2;

            if (v[m].first > timestamp ) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }

        int result = l - 1;

        if (result < 0) {
            return "";
        }

        return v[result].second;


    }
};
