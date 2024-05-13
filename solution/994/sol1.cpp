class Solution {
private:
    constexpr static int dx[4]={0, 1, 0, -1};
    constexpr static int dy[4]={1, 0, -1, 0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> Q;
        vector<vector<int>> dis(10, vector<int>(10, -1));
        int cnt = 0;
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    Q.push({i, j});
                    dis[i][j] = 0;
                } else if (grid[i][j] == 1) {
                    cnt += 1;
                }
            }
        }
        while (!Q.empty()) {
            auto [x, y] = Q.front(); Q.pop();
            for (int i = 0; i < 4; ++i) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx < 0|| tx >= n || ty < 0|| ty >= m || ~dis[tx][ty] || !grid[tx][ty]) {
                    continue;
                }
                dis[tx][ty] = dis[x][y] + 1;
                Q.push({ tx, ty });
                if (grid[tx][ty] == 1) {
                    cnt -= 1;
                    ans = dis[tx][ty];
                    if (!cnt) {
                        break;
                    }
                }
            }
        }
        return cnt ? -1 : ans;
    }
};
