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
    pair<int, int> rob1(TreeNode* root) {
        if (root == nullptr) {
            return { 0, 0 };
        }

        const auto& [l0, l1] = rob1(root->left);
        const auto& [r0, r1] = rob1(root->right);

        return { max(l0, l1) + max(r0, r1), l0 + r0 + root->val };
    }
    int rob(TreeNode* root) {
        const auto& [root0, root1] = rob1(root);
        return max(root0, root1);
    }
};
