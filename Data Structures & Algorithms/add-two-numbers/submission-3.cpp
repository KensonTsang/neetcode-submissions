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
        
        ListNode dummy{};
        ListNode* cur = &dummy;

        int plusOne = 0;
        while(l1 != nullptr ||  l2 != nullptr || plusOne > 0) {
            int l1Val = (l1 != nullptr)? l1->val : 0;
            int l2Val = (l2 != nullptr)? l2->val : 0;
            
            int sum = l1Val + l2Val + plusOne;
            plusOne = (sum > 9)?1:0;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy.next;
        

    }
};
