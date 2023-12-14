// 以空的格子为左上角，如果可以放邮票，就放，最后统计被邮票覆盖的格子和被占据的格子数量和是不是等于 n * m 即可
// 检查是否可以放邮票可以二维前缀和维护被占据格子数量和，O(1) 差分得到
// 放邮票打二维差分标记，最后还原二维数组即可
// 时间复杂度 O(nm)
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> st(n + 2, vector<int>(m + 2, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i + 1][j + 1] = mat[i][j + 1] + mat[i + 1][j] - mat[i][j] + (grid[i][j] == 1);
            }
        }

        auto cnt = [&](int a, int b, int x, int y) -> bool {
            return mat[x][y] - mat[x][b - 1] - mat[a - 1][y] + mat[a - 1][b - 1];
        };

        for (int i = 0; i + stampHeight - 1 < n; ++i) {
            for (int j = 0; j + stampWidth - 1 < m; ++j) if (grid[i][j] == 0) {
                int nxt_x = i + stampHeight - 1;
                int nxt_y = j + stampWidth - 1;
                if (cnt(i + 1, j + 1, nxt_x + 1, nxt_y + 1) == 0) {
                    st[i + 1][j + 1] += 1;
                    st[nxt_x + 2][j + 1] -= 1;
                    st[i + 1][nxt_y + 2] -= 1;
                    st[nxt_x + 2][nxt_y + 2] += 1;
                }
            }
        }

        int c = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                st[i][j] = st[i][j] + st[i - 1][j] + st[i][j - 1] - st[i - 1][j - 1];
                c += st[i][j] > 0;
            }
        }

        return c + mat[n][m] == n * m;
    }
};
