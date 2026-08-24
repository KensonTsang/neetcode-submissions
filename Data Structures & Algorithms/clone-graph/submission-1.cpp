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
        
        unordered_map<Node*, Node*> mapping{};
        mapping[node] = new Node(node->val);

        queue<Node*> q{};
        q.push(node);

        while (q.size() > 0) {
            auto* top = q.front();
            q.pop();

            for (auto* n : top->neighbors) {

                if (mapping.count(n) == 0) {     // add to the map
                    mapping[n] = new Node(n->val);
                    q.push(n);
                }

                mapping[top]->neighbors.push_back(mapping[n]);

            }


        }
        

        return mapping[node];


    }
};
