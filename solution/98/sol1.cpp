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
    struct Node{
        int val,L,R;
        bool isValid;
    };
    Node get(TreeNode* root) {
        Node t=(Node){root->val,root->val,root->val,1};
        if (root->left!=nullptr) {
            Node t2=get(root->left);
            if (t2.isValid==false) t.isValid=false;
            else if (t2.R>=root->val) t.isValid=false;
            else t.L=t2.L;
        }
        if (root->right!=nullptr){
            Node t2=get(root->right);
            if (t2.isValid==false) t.isValid=false;
            else if (t2.L<=root->val) t.isValid=false;
            else t.R=t2.R;
        }
        return t;
    }
    bool isValidBST(TreeNode* root) {
        if (root==nullptr) return true;
        return get(root).isValid;
    }
};

