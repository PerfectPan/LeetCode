class Solution {
public:
    int dp[110][110];
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (~dp[i][j]) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                    } else {
                        dp[i][j] = dp[i - 1][k] + moveCost[grid[i - 1][k]][j] + grid[i][j];
                    }
                    
                }
            }
        }
        int res = 1e9;
        for (int i = 0; i < m; ++i) res = min(res, dp[n - 1][i]);
        return res;
    }
};

