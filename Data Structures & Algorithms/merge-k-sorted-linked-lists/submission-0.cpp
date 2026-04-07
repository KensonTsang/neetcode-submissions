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

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode dummyNode;
        dummyNode.next = nullptr;
        ListNode* cur = &dummyNode;

        while(l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1 != nullptr) {
            cur->next = l1;
        }
        else if(l2 != nullptr) {
            cur->next = l2;
        }

        return dummyNode.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        while(lists.size() > 1) {
            vector<ListNode*> mergedList{};
            for (size_t i = 0 ; i < lists.size() ; i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < lists.size()? lists[i + 1] : nullptr;
                mergedList.push_back(mergeLists(l1,l2));
            }
            lists = mergedList;
        }
        return lists[0];
    }
};
