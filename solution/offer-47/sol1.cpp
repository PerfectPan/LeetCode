// dp[i][j] 表示到 (i - 1, j - 1) 下标的最大的礼物数
// 转移方程 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
// 然后第一维可以去掉，空间复杂度降低至 O(n)
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[j] = max(dp[j - 1], dp[j]) + grid[i - 1][j - 1];
            }
        }
        return dp[m];
    }
};
