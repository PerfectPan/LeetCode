// 假设对格子 C，人在 t_1 分钟到达（最短），火在 t_2 分钟到达（最短）
// 在 t_1 < t_2 时，人在初始位置停留 t_2 - t_1 - 1 分钟，也可以比火先到达 C，且中途不会被火烧到（反证法，假设中途会被火烧到，那么火可以沿着人走的路径到 C，时间应该就是 t_2 - 1 而不是 t_2，产生矛盾）
// 然后安全屋允许人和火同时抵达，所以需要判断 t_2 - t_1 是否满足条件，检查的方法就是查看安全屋的左边和上边的格子
// 如果停留了 t_2 - t_1 以后人先比火到达安全屋左边或上边相邻格子，则满足条件，否则答案为 t_2 - t_1 - 1
// 时间复杂度 O(nm)
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        auto bfs = [&](vector<pair<int, int>>& st) -> tuple<int, int, int> {
            vector<vector<int>> time(n, vector<int>(m, -1));
            queue<pair<int, int>> Q;
            for (auto& [x, y]: st) {
                time[x][y] = 0;
                Q.push({ x, y });
            }
            while (!Q.empty()) {
                auto [x, y] = Q.front(); Q.pop();
                for (int i = 0; i < 4; ++i) {
                    int tx = dx[i] + x;
                    int ty = dy[i] + y;
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m || time[tx][ty] >= 0 || grid[tx][ty] == 2) {
                        continue;
                    }
                    
                    time[tx][ty] = time[x][y] + 1;
                    Q.push({ tx, ty });
                }
            }
            return { time[n - 1][m - 1], time[n - 1][m - 2], time[n - 2][m - 1] };
        };

        vector<pair<int, int>> man = {{0, 0}};
        auto [man_to_house_time, m1, m2] = bfs(man);

        if (man_to_house_time < 0) {
            return -1;
        }

        vector<pair<int, int>> fire;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    fire.push_back({i, j});
                }
            }
        }

        auto [fire_to_house_time, f1, f2] = bfs(fire);

        if (fire_to_house_time < 0) {
            return 1e9;
        }

        int d = fire_to_house_time - man_to_house_time;
        if (d < 0) {
            return -1;
        }

        if ((m1 != -1 && m1 + d < f1) || (m2 != -1 && m2 + d < f2)) {
            return d;
        }

        return d - 1;
    }
};
