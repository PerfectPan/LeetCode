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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        vector<int> preorderL, preorderR;
        vector<int> postorderL, postorderR;
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) {
            return root;
        }
        int leftRt = preorder[1];
        int r = 0;
        for ( ; postorder[r] != leftRt; ++r) {
            postorderL.push_back(postorder[r]);
        }
        postorderL.push_back(postorder[r]);
        r++;
        for ( ; r + 1 < postorder.size(); ++r) {
            postorderR.push_back(postorder[r]);
        }

        int l = 1;
        for (int i = 0; i < postorderL.size(); ++i, ++l) {
            preorderL.push_back(preorder[l]);
        }
        for (; l < preorder.size(); ++l) {
            preorderR.push_back(preorder[l]);
        }

        root->left = constructFromPrePost(preorderL, postorderL);
        root->right = constructFromPrePost(preorderR, postorderR);

        return root;
    }
};
