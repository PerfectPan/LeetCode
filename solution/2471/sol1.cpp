struct Node {
    int idx, val;
    bool operator < (const Node& rhs) const {
        return val < rhs.val;
    }
};
class Solution {
public:
    vector<vector<int>> vec;
    void dfs(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }
        if (vec.size() == level) {
            vec.push_back(vector<int>{});
        }
        vec[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        dfs(root, 0);
        for (int i = 0; i < vec.size(); ++i) {
            vector<Node> res;
            for (int j = 0; j < vec[i].size(); ++j) {
                res.push_back((Node){j, vec[i][j]});
            }
            sort(res.begin(), res.end());
            vector<int> vis(res.size(), 0);
            for (int j = 0; j < res.size(); ++j) if (!vis[j]) {
                int cnt = 0, ptr = j;
                while (!vis[ptr]) {
                    vis[ptr] = 1;
                    ptr = res[ptr].idx;
                    cnt++;
                }
                ans += cnt - 1;
            }
        }
        return ans;
    }
};
