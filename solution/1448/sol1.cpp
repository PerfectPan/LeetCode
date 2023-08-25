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
    int count(TreeNode* root, int val) {
        if (root == nullptr) {
            return 0;
        }
        return (val <= root->val) + count(root->left, max(root->val, val)) + count(root->right, max(root->val, val));
    }
    int goodNodes(TreeNode* root) {
        return count(root, -1e5);
    }
};
