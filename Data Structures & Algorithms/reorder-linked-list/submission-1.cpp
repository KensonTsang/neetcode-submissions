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

    // Find the MidNode of of the ListNode
    ListNode* FindMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;

    }

    ListNode* ReverseNode(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;

    }

    void reorderList(ListNode* head) {

        if (!head || !head->next)
            return;
        
        ListNode* mid = FindMid(head);
        ListNode* rHead = ReverseNode(mid->next);
        mid->next = nullptr;

        while (rHead != nullptr) {
            ListNode* headNext = head->next;
            ListNode* rHeadNext = rHead->next;

            head->next = rHead;
            rHead->next = headNext;

            head = headNext;
            rHead = rHeadNext;

        }
    }
};
