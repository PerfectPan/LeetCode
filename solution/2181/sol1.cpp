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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* t_head = head;

        while (t_head != nullptr) {
            auto next_node = t_head->next;
            if (next_node->val != 0) {
                t_head->val += next_node->val;
                t_head->next = next_node->next;
                next_node->next = nullptr;
            } else if (t_head->next->next == nullptr) {
                t_head->next = nullptr;
                break;
            } else {
                t_head = t_head->next;
            }
        }


        return head;
    }
};
