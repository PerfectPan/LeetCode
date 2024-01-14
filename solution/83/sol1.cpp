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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp_head = head;
        while (tmp_head != nullptr && tmp_head->next != nullptr) {
            if (tmp_head->next->val == tmp_head->val) {
                tmp_head->next = tmp_head->next->next;
            } else {
                tmp_head = tmp_head->next;
            }
        }
        return head;
    }
};
