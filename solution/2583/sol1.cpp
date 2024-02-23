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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;
        queue<TreeNode*> Q;
        if (root == nullptr) {
            return -1;
        }
        Q.push(root);
        while (!Q.empty()) {
            int sz = Q.size();
            long long sum = 0;
            for (int i = 1; i <= sz; ++i) {
                auto node = Q.front(); Q.pop();
                sum += node->val;
                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
            }
            res.push_back(sum);
        }
        int n = res.size();
        if (res.size() < k) {
            return -1;
        }
        ranges::nth_element(res, res.begin() + (n - k));
        return res[n - k];
    }
};
