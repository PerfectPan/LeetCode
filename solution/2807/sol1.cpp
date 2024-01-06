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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* t_head = head;
        while (t_head->next) {
            t_head->next = new ListNode(gcd(t_head->val, t_head->next->val), t_head->next);
            t_head = t_head->next->next;
        }
        return head;
    }
};
