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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> Q;
        if (root != nullptr) {
            Q.push(root);
        }

        int order = 0;
        while (!Q.empty()) {
            int sz = Q.size();
            vector<int> level;
            queue<TreeNode*> tmp;
            for (int i = 1; i <= sz; ++i) {
                auto node = Q.front(); Q.pop();
                level.push_back(node->val);
                if (node->left) {
                    tmp.push(node->left);
                }
                if (node->right) {
                    tmp.push(node->right);
                }
            }
            if (order) {
                reverse(level.begin(), level.end());
            }
            order ^= 1;
            res.push_back(level);
            Q.swap(tmp);
        }

        return res;
    }
};
