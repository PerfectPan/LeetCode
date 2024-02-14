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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> Q;
        if (root != nullptr) {
            Q.push(root);
        }
        while (!Q.empty()) {
            int currentLevelSize = Q.size();
            vector<int> level;
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = Q.front(); Q.pop();
                level.push_back(node->val);
                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
            }
            res.emplace_back(move(level));
        }
        return res;
    }
};
