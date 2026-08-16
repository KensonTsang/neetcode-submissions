/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> _map{};
        _map[node] = new Node(node->val);
        
        queue<Node*> q{};
        q.push(node);


        while(q.size() > 0) {
            auto* cur = q.front();
            q.pop();
            for (auto* n : cur->neighbors) {
                if (_map.find(n) == _map.end()) {
                    _map[n] = new Node(n->val);
                    q.push(n);
                }
                _map[cur]->neighbors.push_back(_map[n]);
            }

        }

        
        return _map[node];

    }
};
