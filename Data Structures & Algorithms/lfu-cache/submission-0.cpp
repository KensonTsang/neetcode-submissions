class LFUCache {
    struct Node {
        int key;
        int value;
        int freq;
        int tick;
    };
    struct Compare {
        bool operator()(const Node* lhs, const Node* rhs) const {
            if (lhs->freq != rhs->freq)
                return lhs->freq < rhs->freq;

            return lhs->tick < rhs->tick;
        }
    };

public:

    unordered_map<int, Node*> map_;
    set<Node*, Compare> nodeSet_;
    int cap_;
    int tick_;

    LFUCache(int capacity) {
        cap_ = capacity;
        tick_ = 0;
    }

    int get(int key) {

        if (map_.count(key) == 0) {
            return -1;
        }

        updateFreq(map_[key]);

        return map_[key]->value;
    }

    void put(int key, int value) {

        if (cap_ == 0)
            return;

        // Key already exists
        if (map_.count(key) > 0) {
            updateFreq(map_[key]);
            map_[key]->value = value;
            return;
        }

        // Cache is full
        if (nodeSet_.size() >= cap_) {
            Node* node = *nodeSet_.begin();

            map_.erase(node->key);
            nodeSet_.erase(node);

            delete node;
        }

        // Insert new node
        Node* node = new Node();

        node->key = key;
        node->value = value;
        node->freq = 1;
        node->tick = ++tick_;

        map_[key] = node;
        nodeSet_.insert(node);
    }

    void updateFreq(Node* node) {

        // Remove first because freq/tick affect ordering
        nodeSet_.erase(node);

        node->freq++;
        node->tick = ++tick_;

        // Insert again with new ordering
        nodeSet_.insert(node);
    }
};