/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> _map{};


        //
        // <3, new3>, <7, new7>, <4, new4>, <4, new5> 
        Node* cur = head;
        while(cur != nullptr) {
            _map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur != nullptr) {
            Node* newCur = _map[cur];            
            newCur->next = _map[cur->next];
            newCur->random = _map[cur->random];
            cur = cur->next;
        }


        return _map[head];


    }
};
