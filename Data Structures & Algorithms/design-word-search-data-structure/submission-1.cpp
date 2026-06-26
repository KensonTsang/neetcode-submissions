struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto* cur = root;

        for(auto c : word) {
            if (!cur->children.count(c)){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }

        cur->isWord = true;        
    }

    bool dfs(string& word, int j, TrieNode* root) {
        auto* cur = root;

        for (int i = j ; i < word.size() ; i++) {
            char c = word[i];

            if (c == '.') {
                for (auto& p : cur->children) {
                    if (p.second != nullptr && dfs(word, i + 1, p.second)) {
                        return true;
                    }                    
                }
                return false;
            }
            else {
                if (!cur->children.count(c)) {
                    return false;
                }
                cur = cur->children[c];
            }

        }
        return cur->isWord;
    }

    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
