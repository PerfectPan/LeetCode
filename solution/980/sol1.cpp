// 数据范围很小，暴力搜索即可
class Solution {
public:
    int vis[21][21], sx, sy, ex, ey, total;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(vector<vector<int>>& grid, int x, int y, int step, int& ans) {
        if (x == ex && y == ey) {
            ans += step == total;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < grid.size() && nx >=0 && ny >= 0 && ny < grid[0].size()) {
                if (grid[nx][ny] != -1 && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    dfs(grid, nx, ny, step + (grid[nx][ny] == 0), ans);
                    vis[nx][ny] = 0;
                }
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
                if (grid[i][j] == 2) {
                    ex = i;
                    ey = j;
                }
                if (grid[i][j] == 0) {
                    total++;
                }
            }
        }
        vis[sx][sy] = 1;
        dfs(grid, sx, sy, 0, ans);
        return ans;
    }
};
