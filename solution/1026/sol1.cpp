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
    int ans = 0;
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return { -1, 1e9 };
        }
        int mx = -1, mn = 1e9;
        
        if (root->left) {
            auto [mxx, mnn] = dfs(root->left);
            mx = max(mx, mxx);
            mn = min(mn, mnn);
        }
        if (root->right) {
            auto [mxx, mnn] = dfs(root->right);
            mx = max(mx, mxx);
            mn = min(mn, mnn);
        }

        if (mn < 1e9) {
            ans = max(ans, abs(root->val - mn));
        }
        if (mx > -1) {
            ans = max(ans, abs(root->val - mx));
        }

        return { max(mx, root->val), min(mn, root->val) };
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
