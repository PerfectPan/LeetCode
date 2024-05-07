// dp[i][j][k] 表示第 i 行，机器人 1 在第 j 列，机器人 2 在第 k 列的最大樱桃数，枚举前一行转移即可
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    int val = grid[i][j] + (j == k ? 0 : grid[i][k]);
                    for (int d_x = -1; d_x <= 1; ++d_x) {
                        for (int d_y = -1; d_y <= 1; ++d_y) {
                            int pre_x = j + d_x, pre_y = k + d_y;
                            if (pre_x < 0 || pre_x >= m || pre_y < 0 || pre_y >= m || dp[i - 1][pre_x][pre_y] == -1) {
                                continue;
                            }
                            if (dp[i][j][k] == -1) {
                                dp[i][j][k] = dp[i - 1][pre_x][pre_y] + val;
                            } else {
                                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][pre_x][pre_y] + val);
                            }
                        }
                    }

                    if (i == n - 1) {
                        ans = max(ans, dp[i][j][k]);
                    }
                }
            }
        }
        return ans;
    }
};
