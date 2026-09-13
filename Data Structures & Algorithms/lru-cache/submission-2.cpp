class LRUCache {

private:
    struct Node{

        Node* prev;
        Node* next;
        int value;
        int key;

        Node(int key, int value):prev(nullptr), next(nullptr), value(value), key(key) {        
        }

    };

    int capacity_;
    unordered_map<int, Node*> map_;
    Node* head_;
    Node* tail_;

    void setHead(Node* node) {      // set the head

        if (head_ != nullptr) {
            head_->prev = node;    // old head->prev to new node (new head)
        }

        node->prev = nullptr;       // head doesn't contain any prev
        node->next = head_;         // node's next should be the old head
        head_ = node;

        if (tail_ == nullptr) {
            tail_ = node;
        }


    }

    void remove(Node* node) {       // remove the node from the linkedlist

        if (node->prev) {
            node->prev->next = node->next;
        } else {
            head_ = node->next;
        }

        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail_ = node->prev;
        }

        node->prev = nullptr;
        node->next = nullptr;

    }


public:

    LRUCache(int capacity) {
        capacity_ = capacity;
        head_ = nullptr;
        tail_ = nullptr;
    }
    
    int get(int key) {
        
        if (!map_.count(key)) {     // not exist in the cache list
            return -1;
        }
        
        remove(map_[key]);
        setHead(map_[key]);

        return map_[key]->value;

    }
    
    void put(int key, int value) {
        
        if (map_.count(key)) {
            auto* node = map_[key];
            node->value = value;
            remove(map_[key]);
            setHead(map_[key]);
            return;
        }

        if (map_.size() >= capacity_) {
            // remove the tail
            // delete the node (avoid the memory leak)

            auto* prevTail = tail_; // store the ptr
            remove(tail_);          // remove the prev & next linkage
            map_.erase(prevTail->key);   // remove it to the list
            delete prevTail;        // release the memory

        }

        auto* nodePtr = new Node(key, value);
        setHead(nodePtr);
        map_[key] = nodePtr;

        // create a new node
        // set to the head  



    }


};
