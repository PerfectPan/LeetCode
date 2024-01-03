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
    ListNode* removeNodesInner(ListNode* prev, ListNode* cur) {
        if (cur == nullptr) {
            return prev;
        }
        ListNode* head = removeNodesInner(cur, cur->next);
        if (!head || prev->val >= head->val) {
            prev->next = head;
            return prev;
        }
        return head;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummyNode = new ListNode(1e6, head);
        return removeNodesInner(dummyNode, head)->next;
    }
};
