class LRUCache {

    struct Node {
        Node* pre;
        Node* next;
        int key;
        int value;

        Node(int key, int value) : pre(nullptr), next(nullptr), key(key), value(value){}
    };


public:

    int cacheSize_;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> map_;

    LRUCache(int capacity) {
        cacheSize_ = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {

        if (map_.find(key) == map_.end()) {
            return -1;
        }

        remove(map_[key]);
        setHead(map_[key]);
        return map_[key]->value;
    }

    void setHead(Node* node) {
        // 1. set the newNode.next = cur_head if cur_head is not null
        // 2. set the cur_head.prev = newNode if cur_head is not null
        // 3. set the cur_head = newNode
        // 4. set the cur_head & tail = newNode if cur_head == null

        node->next = head;
        node->pre = nullptr;

        if (head != nullptr) {            
            head->pre = node;
        }
        
        if (tail == nullptr){            
            tail = node;
        }

        head = node;
       
    }

    void remove(Node* node) {


        if (node->pre != nullptr) {     // connecting
            node->pre->next = node->next;
        }
        else {                          // head
            head = node->next;
        }


        if (node->next != nullptr) {   // connecting
            node->next->pre = node->pre;
        }
        else {                          // tail
            tail = node->pre;
        } 

        node->pre = nullptr;
        node->next = nullptr;


    }

    
    void put(int key, int value) {
        if (map_.find(key) != map_.end()) {
            auto* node = map_[key];
            remove(node);
            node->value = value;
            setHead(node);
            return;
        }

        Node* newNode = new Node(key, value);
        if (map_.size() >= cacheSize_) {
            Node* oldTail = tail;
            map_.erase(oldTail->key);
            remove(oldTail);
            setHead(newNode);
            delete oldTail;            
        }
        else {
            setHead(newNode);
        }
        map_[key] = newNode;


    }
};
