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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummyNode;
        ListNode* dummyPtr = &dummyNode;
        dummyPtr->next = head;

        int i = 1;
        while (i < left) {
            dummyPtr = dummyPtr->next;
            i++;
        }

        ListNode* reverseHead = dummyPtr->next;
        ListNode* pre = nullptr;
        ListNode* cur = dummyPtr->next;

        int reverseTimes = right - left + 1;
        int j = 0;

        while (j < reverseTimes) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            j++;
        }

        dummyPtr->next = pre;
        reverseHead->next = cur;

        return dummyNode.next;
    }
};