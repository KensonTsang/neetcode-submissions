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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummyNode;
        dummyNode.next = head;
        ListNode* groupPre = &dummyNode;

        while (true) {
            ListNode* kthNode = getKthNode(groupPre, k);
            if (kthNode == nullptr) {
                break;
            }

            ListNode* groupNext = kthNode->next;
            ListNode* prev = groupNext;
            ListNode* cur = groupPre->next;
            
            while (cur != groupNext) {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            ListNode* tmp = groupPre->next;
            groupPre->next = kthNode;
            groupPre = tmp;
        }

        return dummyNode.next;

    }

    ListNode* getKthNode(ListNode* cur, int k) {
        while (cur != nullptr && k > 0) {
            cur = cur->next;
            k--;
        }
        return cur;
    }

};
