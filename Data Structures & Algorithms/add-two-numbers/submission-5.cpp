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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode dummy;
        dummy.next = nullptr;
        ListNode* cur = &dummy;

        ListNode* l1_ptr = l1;
        ListNode* l2_ptr = l2;

        bool plusOne = false;

        while (l1_ptr != nullptr || l2_ptr != nullptr || plusOne) {
            int l1_num = l1_ptr != nullptr ? l1_ptr->val : 0;
            int l2_num = l2_ptr != nullptr ? l2_ptr->val : 0;
            int sum = l1_num + l2_num + (int)plusOne;
            plusOne = sum > 9;


            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            if (l1_ptr != nullptr) l1_ptr = l1_ptr->next;
            if (l2_ptr != nullptr) l2_ptr = l2_ptr->next;

        }

        return dummy.next;
    }
};
