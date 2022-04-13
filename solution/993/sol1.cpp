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
    bool flag=0;
    int dep[200];
    void dfs(TreeNode* root,int d,int x,int y){
        if (root==NULL) return;
        dep[root->val]=d+1;
        if (root->left!=NULL && root->right!=NULL){
            if ((root->left->val==x && root->right->val==y)||(root->left->val==y && root->right->val==x)) flag=1;
        }
        dfs(root->left,d+1,x,y);
        dfs(root->right,d+1,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,0,x,y);
        if (flag) return 0;
        if (dep[x]==dep[y]) return 1;
        else return 0;
    }
};

