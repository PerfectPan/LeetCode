class Solution {
public:
    int mx=-2000000000;
    int dfs(TreeNode* root){
        int x=root->val;
        mx=max(mx,x);
        if (root->left!=NULL){
            int y=dfs(root->left);
            mx=max(mx,x+y);
            x=max(x,y+root->val);
        }
        if (root->right!=NULL){
            int y=dfs(root->right);
            mx=max(mx,x+y);
            x=max(x,y+root->val);
        }
        return x;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};

