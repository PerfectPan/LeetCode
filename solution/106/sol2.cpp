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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        int rt = postorder.back();
        TreeNode* root = new TreeNode(rt);
        int r = 0;
        vector<int> inorderL, inorderR;
        for (; inorder[r] != rt; ++r) {
            inorderL.push_back(inorder[r]);
        }
        r += 1;
        for (; r < inorder.size(); ++r) {
            inorderR.push_back(inorder[r]);
        }
        vector<int> postorderL, postorderR;
        int i = 0;
        for (int j = 0; j < inorderL.size(); ++j, ++i) {
            postorderL.push_back(postorder[i]);
        }
        for (int j = 0; j < inorderR.size(); ++j, ++i) {
            postorderR.push_back(postorder[i]);
        }
        root->left = buildTree(inorderL, postorderL);
        root->right = buildTree(inorderR, postorderR);
        return root;
    }
};
