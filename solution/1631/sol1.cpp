// 二分答案，高度差小于答案的可以走，check 用 BFS check 是否能走到终点即可
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int mx = -1, mn = 1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mx = max(mx, heights[i][j]);
                mn = min(mn, heights[i][j]);
            }
        }
        int l = 0, r = mx - mn, ans = 1e6;
        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };

        auto check = [&](int limit) -> bool {
            queue<pair<int, int>> Q;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            Q.push({ 0, 0 });
            vis[0][0] = 1;
            while (!Q.empty()) {
                auto [x, y] = Q.front(); Q.pop();
                if (x == n - 1 && y == m - 1) {
                    return true;
                }
                for (int i = 0; i < 4; ++i) {
                    int tx = x + dx[i];
                    int ty = y + dy[i];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || abs(heights[tx][ty] - heights[x][y]) > limit) {
                        continue;
                    }
                    vis[tx][ty] = 1;
                    Q.push({ tx, ty });
                }
            }
            return false;
        };
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
