// 二叉搜索树的特殊性质决定了 p 和 q 的最近公共祖先是从上往下走第一个节点 v，v 的值小于 p 大于 q，或者 v 的值小于 q 大于 p
// 时间复杂度 O(n)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        for (;;) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            } else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            } else {
                break;
            }
        }
        return ancestor;
    }
};
