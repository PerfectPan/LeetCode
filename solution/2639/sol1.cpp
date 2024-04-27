class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                string num = to_string(grid[j][i]);
                ans[i] = max(ans[i], (int)num.length());
            }
        }
        return ans; 
    }
};
