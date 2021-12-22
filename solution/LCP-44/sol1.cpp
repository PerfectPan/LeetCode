/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    set<int> S;
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        S.insert(root->val);
        dfs(root->left);
        dfs(root->right);
        return;
    }
    int numColor(TreeNode* root) {
        S.clear();
        dfs(root);
        return S.size();
    }
};

