// 中序遍历完得到有序的数组以后，根据 query 直接二分就可以找到答案了
// 时间复杂度 O(n + qlog n)
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
    void dfs(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) {
                return;
        }
        dfs(root->left, vec);
        vec.push_back(root->val);
        dfs(root->right, vec);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> res;
        dfs(root, res);

        vector<vector<int>> ans;
        for (auto& query: queries) {
            int mn = upper_bound(res.begin(), res.end(), query) - res.begin();
            int mx = lower_bound(res.begin(), res.end(), query) - res.begin();
            int A = -1;
            if (mn - 1 >= 0) {
                A = res[mn - 1];
            }
            int B = -1;
            if (mx != res.size()) {
                B = res[mx];
            }
            ans.push_back({ A, B });
        }
        return ans;
    }
};
