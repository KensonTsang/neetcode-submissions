class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> _map{};

    TimeMap() {
        _map = {};
    }
    
    void set(string key, string value, int timestamp) {
        _map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        if (_map.find(key) == _map.end())
            return "";

        auto& vec = _map[key];

        int l = 0;
        int r = vec.size() - 1;

        string ans = "";

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (vec[mid].first <= timestamp) {
                ans = vec[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    
    }
};
