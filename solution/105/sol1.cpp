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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int r = 0;
        vector<int> inorderL, inorderR;
        for (; inorder[r] != preorder[0]; ++r) {
            inorderL.push_back(inorder[r]);
        }
        r += 1;
        for (; r < inorder.size(); ++r) {
            inorderR.push_back(inorder[r]);
        }
        vector<int> preorderL, preorderR;
        int i = 1;
        for (int j = 0; j < inorderL.size(); ++j, ++i) {
            preorderL.push_back(preorder[i]);
        }
        for (int j = 0; j < inorderR.size(); ++j, ++i) {
            preorderR.push_back(preorder[i]);
        }
        root->left = buildTree(preorderL, inorderL);
        root->right = buildTree(preorderR, inorderR);
        return root;
    }
};
