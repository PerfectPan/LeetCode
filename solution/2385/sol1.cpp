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
    vector<int> G[100010];
    void dfs(TreeNode* root) {
        if (root->left) {
            G[root->val].push_back(root->left->val);
            G[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if (root->right) {
            G[root->val].push_back(root->right->val);
            G[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
    void dfs2(int u, int f, int dep, int& mx) {
        mx = max(mx, dep);
        for (int& v: G[u]) {
            if (v == f) {
                continue;
            } 
            dfs2(v, u, dep + 1, mx);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        int mx = 0;
        dfs2(start, -1, 0, mx);
        return mx;
    }
};
