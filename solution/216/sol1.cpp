class Solution {
public:
    void dfs(int k, int idx, int n, vector<int>& path, vector<vector<int>>& ans) {
        if (k == 0) {
            if (n == 0) {
                ans.push_back(path);
            }
            return;
        }
        for (int i = idx; i <= 9; ++i) {
            path.push_back(i);
            dfs(k - 1, i + 1, n - i, path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(k, 1, n, path, ans);
        return ans;
    }
};
