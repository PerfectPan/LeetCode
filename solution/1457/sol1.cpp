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
    int dfs(TreeNode* root, int s) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return __builtin_popcount(s ^ (1 << root->val)) <= 1;
        }
        return dfs(root->left, s ^ (1 << root->val)) + dfs(root->right, s ^ (1 << root->val));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
};
