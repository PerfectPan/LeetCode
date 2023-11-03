// 一层层构建，如果已经知道上一层的链表，那么遍历上一层就可以构建出下一层的链表了
// 时间复杂度 O(n)，空间复杂度 O(1)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* dummy = new Node();
        Node* cur = root;
        while (cur) {
            dummy->next = nullptr;
            Node* nxt = dummy;
            while (cur) {
                if (cur->left) {
                    nxt->next = cur->left;
                    nxt = nxt->next;
                }
                if (cur->right) {
                    nxt->next = cur->right;
                    nxt = nxt->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
        }

        delete dummy;
        return root;
    }
};
