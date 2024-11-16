class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m / 2; ++j) {
                int zero = 0;
                zero += grid[i][j] == 0;
                zero += grid[n - i - 1][j] == 0;
                zero += grid[n - i - 1][m - j - 1] == 0;
                zero += grid[i][m - j - 1] == 0;
                ans += min(zero, 4 - zero);
            }
        }

        int t = 0, t2 = 0;
        if (n & 1) {
            for (int j = 0; j < m / 2; ++j) {
                ans += grid[n / 2][j] != grid[n / 2][m - j - 1];
                t2 += grid[n / 2][j] != grid[n / 2][m - j - 1];
                if (grid[n / 2][j] == grid[n / 2][m - j - 1] and grid[n / 2][j] == 1) {
                    t++;
                }
            }
        }
        if (m & 1) {
            for (int i = 0; i < n / 2; ++i) {
                ans += grid[i][m / 2] != grid[n - i - 1][m / 2];
                t2 += grid[i][m / 2] != grid[n - i - 1][m / 2];
                if (grid[i][m / 2] == grid[n - i - 1][m / 2] and grid[i][m / 2] == 1) {
                    t++;
                }
            }
        }
        if (t % 2 != 0 && t2 == 0) {
            ans += 2;
        }

        if ((n & 1) and (m & 1)) {
            ans += grid[n / 2][m / 2] == 1;
        }
        return ans;
    }
};
