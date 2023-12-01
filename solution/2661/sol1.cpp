constexpr int dx[4] = { 0, 1, 0, -1 };
constexpr int dy[4] = { 1, 0, -1, 0 };

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int row[n][m], col[m][n];
        int sz_row[n][m], sz_col[m][n];
        int vis[n][m];
        pair<int, int> pos[n * m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                row[i][j] = j;
                sz_row[i][j] = 1;
                col[j][i] = i;
                sz_col[j][i] = 1;
                vis[i][j] = 0;
                pos[mat[i][j] - 1] = { i, j };
            }
        }

        function<int(int, int*)> find = [&](int x, int* fa) -> int {
            return x == fa[x] ? x : fa[x] = find(fa[x], fa);
        };

        auto merge = [&](int* fa, int* sz, int x, int y) -> void {
            int rt_x = find(x, fa), rt_y = find(y, fa);
            if (rt_x == rt_y) {
                return;
            }
            if (sz[rt_x] <= sz[rt_y]) {
                fa[rt_x] = rt_y;
                sz[rt_y] += sz[rt_x];
            } else {
                fa[rt_y] = rt_x;
                sz[rt_x] += sz[rt_y];
            }
        };

        for (int j = 0; j < n * m; ++j) {
            auto& [x, y] = pos[arr[j] - 1];
            vis[x][y] = 1;
            for (int i = 0; i < 4; ++i) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;

                if (vis[tx][ty]) {
                    bool is_row = i % 2 == 0;
                    if (is_row) {
                        merge(row[tx], sz_row[tx], ty, y);
                    } else {
                        merge(col[ty], sz_col[ty], tx, x);
                    }
                }               
            }
            if (sz_col[y][find(x, col[y])] == n || sz_row[x][find(y, row[x])] == m) {
                return j;
            }
        }

        return 0;
    }
};
