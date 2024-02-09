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
    TreeNode* res;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        if ((left && right) || ((root->val == p->val || root->val == q->val) && (left || right))) {
            res = root;
        }
        return left || right || root->val == p->val || root->val == q->val;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       dfs(root, p, q);
       return res; 
    }
};
