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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> Q;
        if (root != nullptr) {
            Q.push(root);
        }

        while (!Q.empty()) {
            int sz = Q.size();
            res.push_back(vector<int>());
            for (int i = 1; i <= sz; ++i) {
                auto node = Q.front(); Q.pop();
                res.back().push_back(node->val);
                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
