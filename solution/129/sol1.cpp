class Solution {
public:
  int dfs(TreeNode *root, int prevSum) {
    if (!root) {
      return 0;
    }
    int sum = prevSum * 10 + root->val;
    return !root->left && !root->right
               ? sum
               : dfs(root->left, sum) + dfs(root->right, sum);
  }
  int sumNumbers(TreeNode *root) { return dfs(root, 0); }
};
