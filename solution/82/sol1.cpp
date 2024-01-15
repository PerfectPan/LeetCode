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
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* tmp = dummyNode->next;
        ListNode* lst = dummyNode;

        while (tmp && tmp->next) {
            if (tmp->val == tmp->next->val) {
                while (tmp->next && tmp->val == tmp->next->val) {
                    tmp->next = tmp->next->next;
                }
                if (lst) {
                    lst->next = tmp->next;
                    tmp = tmp->next;
                }
            } else {
                lst = tmp;
                tmp = tmp->next;
            }
        }
        return dummyNode->next;
    }
};
