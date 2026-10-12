class LFUCache {

struct CacheNode{
    int key;
    int value;
    int freq;
    std::list<int>::const_iterator it;
};


public:
    LFUCache(int capacity) {
        cap_ = capacity;
        minFreq_ = 0;        
    }
    
    int get(int key) {
        
        auto it = map_.find(key);
        if (it == map_.cend()) {
            return - 1;
        }

        touch(it->second);

        return it->second.value;
    }
    
    void put(int key, int value) {
        
        if (cap_ == 0) {
            return;
        }

        auto it = map_.find(key);
        if (it != map_.cend()) {
            touch(it->second);
            it->second.value = value;
            return;
        }

        if (cap_ == map_.size()) {
            // remove the least freq use
            const int keyToRemove = list_[minFreq_].back();
            list_[minFreq_].pop_back();

            map_.erase(keyToRemove);
        }

        int freq = 1;
        minFreq_ = freq;

        list_[freq].push_front(key);
        map_[key] = {key, value, freq, list_[freq].cbegin()};

    }

private:


    void touch(CacheNode& node) {
        
        int prev_freq = node.freq;
        int freq = prev_freq + 1;

        // remove from the old freq list
        list_[prev_freq].erase(node.it);

        // add to new freq list
        list_[freq].push_front(node.key);
        node.freq = freq;
        node.it = list_[freq].cbegin();

        if (list_[prev_freq].size() <= 0 &&
            prev_freq == minFreq_) {
            
            list_.erase(prev_freq);
            minFreq_ = freq;

        }

    


    }


    int cap_;
    int minFreq_;

    unordered_map<int, CacheNode> map_;
    unordered_map<int, list<int>> list_;

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */