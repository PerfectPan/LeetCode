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
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, nullptr};
        }
        auto [left_mx, left_lca] = dfs(root->left);
        auto [right_mx, right_lca] = dfs(root->right);
        if (left_mx < right_mx) {
            return {right_mx + 1, right_lca};
        }
        if (left_mx > right_mx) {
            return {left_mx + 1, left_lca};
        }
        return {left_mx + 1, root};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};
