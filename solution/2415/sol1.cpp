// DFS 的时候待交换的节点的路径是可以一起 DFS 出来的
// 因此 DFS 对称的节点，在奇数层将其值交换即可
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
    void exchange(TreeNode* root1, TreeNode* root2, bool isOdd) {
        if (root1 == nullptr) {
            return;
        }
        if (isOdd) {
            swap(root1->val, root2->val);
        }
        exchange(root1->left, root2->right, !isOdd);
        exchange(root1->right, root2->left, !isOdd);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        exchange(root->left, root->right, 1);
        return root;
    }
};
