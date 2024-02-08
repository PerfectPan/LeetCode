/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            queue<TreeNode*> Q2;
            TreeNode* x_f = nullptr, *y_f = nullptr;
            while (!Q.empty()) {
                auto node = Q.front(); Q.pop();
                if (node->left) {
                    Q2.push(node->left);
                    if (node->left->val == x) {
                        x_f = node;
                    }
                    if (node->left->val == y) {
                        y_f = node;
                    }
                }
                if (node->right) {
                    Q2.push(node->right);
                    if (node->right->val == x) {
                        x_f = node;
                    }
                    if (node->right->val == y) {
                        y_f = node;
                    }
                }
            }
            if (x_f || y_f) {
                if (x_f && y_f && x_f != y_f) {
                    return true;
                }
                return false;
            }
            Q.swap(Q2);
        }
        return false;
    }
};
