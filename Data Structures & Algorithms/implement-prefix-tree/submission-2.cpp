
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false; 
};


class PrefixTree {
public:

    TrieNode* root;
    

    PrefixTree() {
        root = new TrieNode();       
    }
    
    void insert(string word) {
        auto* cur = root;

        for (auto c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }

        cur->isWord = true;
    }
    
    bool search(string word) {
        auto* cur = root;

        for (auto c : word) {
            if (!cur->children.count(c)) {
                return false;
            }
            cur = cur->children[c];
        }

        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        auto* cur = root;

        for (auto c : prefix) {
            if (!cur->children.count(c)) {
                return false;
            }
            cur = cur->children[c];
        }

        return true;
        
    }
};
