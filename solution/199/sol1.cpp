class Solution {
public:
    void dfs(TreeNode* root,int dep,vector<int>&res){
        if (res.size()<=dep) res.push_back(root->val);
        if (root->right!=NULL) dfs(root->right,dep+1,res);
        if (root->left!=NULL) dfs(root->left,dep+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;res.clear();
        if (root!=NULL) dfs(root, 0, res);
        return res;
    }
};

