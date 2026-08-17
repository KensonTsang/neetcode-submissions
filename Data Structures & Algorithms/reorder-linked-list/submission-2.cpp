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

    ListNode* findMid(ListNode* head) {
        auto* slow = head;
        auto* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {        
        ListNode* pre = nullptr;

        while (head != nullptr) {
            auto* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }


    void reorderList(ListNode* head) {
        
        auto* mid = findMid(head);
        auto* rHead = reverseList(mid->next);
        mid->next = nullptr;

        while (head != nullptr && rHead != nullptr) {
            auto* headNext = head->next;
            auto* rHeadNext = rHead->next;

            head->next = rHead;
            rHead->next = headNext;

            head = headNext;
            rHead = rHeadNext;
        }

        if (rHead != nullptr) {
            head->next = rHead;
        }



    }
};
