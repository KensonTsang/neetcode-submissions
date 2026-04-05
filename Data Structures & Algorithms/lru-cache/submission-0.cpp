class LRUCache {

private: 

    struct Node {
        Node* pre;
        Node* next;
        int key;
        int value;

        Node(int key, int value):pre(nullptr), next(nullptr), key(key), value(value){}
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> hash;
    int cacheSize;


public:
    LRUCache(int capacity) {
        cacheSize = capacity;
        head = nullptr;
        tail = nullptr;        
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }

        Node* node = hash[key];
        remove(node);
        setHead(node);
        return node->value;
    }
    
    void put(int key, int value) {              

        if (hash.find(key) != hash.end()) {
            Node* node = hash[key];
            remove(node);
            node->value = value;
            setHead(node);
            return;
        }
        
        Node* newNode = new Node(key, value);

        if (hash.size() >= cacheSize) {
            Node* oldTail = tail;
            hash.erase(oldTail->key);
            remove(oldTail);
            setHead(newNode);
            delete oldTail;
        }
        else {
            setHead(newNode);
        }
        hash[key] = newNode;
        

    }

    void setHead(Node* node){
        node->next = head;
        node->pre = nullptr;
        if(head != nullptr) {
            head->pre = node;
        }
        head = node;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void remove(Node* node) {

        if (node->pre != nullptr) {
            node->pre->next = node->next;
        }
        else {
            head = node->next;
        }    

        if (node->next != nullptr) {
            node->next->pre = node->pre;
        }
        else {
            tail = node->pre;
        }

        node->pre = nullptr;
        node->next = nullptr;
    }
};
