// 分治合并，传递下标减少数据的拷贝
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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode head, *tail = &head;
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return head.next;
    }
    ListNode* mergeKList(vector<ListNode*>& lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        if (l > r) {
            return nullptr;
        }
        int mid = l + ((r - l) >> 1);
        return merge(mergeKList(lists, l, mid), mergeKList(lists, mid + 1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKList(lists, 0, (int)lists.size() - 1);
    }
};
