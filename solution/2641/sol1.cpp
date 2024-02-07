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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> Q;
        root->val = 0;
        Q.push(root);
        auto getVal = [](TreeNode* root) {
            int v = 0;
            if (root->left) {
                v += root->left->val;
            }
            if (root->right) {
                v += root->right->val;
            }
            return v;
        };
        while (!Q.empty()) {
            queue<TreeNode*> Q2;
            int sum = 0;
            while (!Q.empty()) {
                auto node = Q.front(); Q.pop(); Q2.push(node);
                sum += getVal(node);
            }
            while (!Q2.empty()) {
                auto node = Q2.front(); Q2.pop();
                int v = getVal(node);
                if (node->left) {
                    node->left->val = sum - v;
                    Q.push(node->left);
                }
                if (node->right) {
                    node->right->val = sum - v;
                    Q.push(node->right);
                }
            }
        }
        return root;
    }
};
