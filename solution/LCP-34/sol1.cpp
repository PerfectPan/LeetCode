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
    vector<int> dfs(TreeNode* root, int k) {
      vector<int> dp(k + 1, -1);
      dp[0] = 0;
      if (root == nullptr) {
        return dp;
      }

      vector<int> L = dfs(root->left, k);
      vector<int> R = dfs(root->right, k);

      for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= i - 1; ++j) {
          if (L[j] >= 0 && R[i - 1 - j] >= 0) {
            dp[i] = max(dp[i], L[j] + R[i - 1 - j] + root->val);
          }
        }
      }

      dp[0] = *max_element(L.begin(), L.end()) + *max_element(R.begin(), R.end());

      return dp;
    }
    int maxValue(TreeNode* root, int k) {
      vector<int> ans = dfs(root, k);

      return *max_element(ans.begin(), ans.end());
    }
};


