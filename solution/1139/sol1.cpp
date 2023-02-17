class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> gd(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                gd[i + 1][j + 1] = gd[i + 1][j] + gd[i][j + 1] + (grid[i][j] == 1) - gd[i][j];
            }
        }

        function<int(int, int, int, int)> cnt = [&](int a, int b, int c, int d) -> int {
            return gd[c][d] - gd[c][b] - gd[a][d] + gd[a][b];
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 1; k <= min(n, m) && i + k <= n && j + k <= m; ++k) {
                    if (cnt(i + k - 1, j, i + k, j + k) == k && cnt(i, j + k - 1, i + k, j + k) == k && cnt(i, j, i + 1, j + k) == k && cnt(i, j, i + k, j + 1) == k) {
                        ans = max(ans, k * k);
                    }
                }
            }
        }
        return ans;
    }
};
