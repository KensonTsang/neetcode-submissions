class TimeMap {
public:

    struct KeyObj {
        int m_timestamp;
        string m_value;

        KeyObj(int timestamp, string value) : m_timestamp(timestamp), m_value(std::move(value)){}
    };

    unordered_map<string,vector<KeyObj>> dataStore;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dataStore[key].emplace_back(timestamp, std::move(value));
    }
    
    string get(string key, int timestamp) {
        if (dataStore.find(key) == dataStore.end())
            return "";

        auto& objs = dataStore[key];
        int l = 0;
        int r = objs.size() - 1;

        while (l <= r) {
            int m = l + ((r - l) / 2);

            if (objs[m].m_timestamp > timestamp) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        if (r < 0) return "";
        return objs[r].m_value;
    }
};
