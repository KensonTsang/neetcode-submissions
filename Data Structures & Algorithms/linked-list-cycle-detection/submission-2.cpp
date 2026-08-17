/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        
        ListNode* fastP = head;
        ListNode* slowP = head;

        while (slowP != nullptr) {
            
            slowP = slowP->next;
            if (fastP != nullptr && fastP->next != nullptr) {
                fastP = fastP->next->next;
            }
            else {
                return false;
            }
            
            if (slowP == fastP) {
                return true;
            }

        }

        return false;

    }
};
