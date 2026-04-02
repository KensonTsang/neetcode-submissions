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

    ListNode* FindMid(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;

    }

    ListNode* ReverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    
        return prev;
    }


    void reorderList(ListNode* head) {
        

        ListNode* mid = FindMid(head);
        ListNode* rhead = ReverseList(mid->next);
        mid->next = nullptr;
        

        while(rhead != nullptr) {
            ListNode* next = head->next;
            ListNode* rnext = rhead->next;

            head->next = rhead;
            rhead->next = next;

            head = next;
            rhead = rnext;

        }
    }
};
