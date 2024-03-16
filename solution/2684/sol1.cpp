class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int> > Q;
        for (int i = 0; i < n; ++i) {
            Q.push({ i, 0 });
            vis[i][0] = 1;
        }
        int mx = 0;
        while (!Q.empty()) {
            auto [x, y] = Q.front(); Q.pop();
            mx = max(mx, y);
            if (y + 1 >= m) {
                continue;
            }
            int L = max(x - 1, 0), R = min(x + 1, n - 1);
            for (int i = L; i <= R; ++i) {
                if (grid[i][y + 1] > grid[x][y] && !vis[i][y + 1]) {
                    Q.push({ i, y + 1 });
                    vis[i][y + 1] = 1;
                }
            }
        }
        return mx;
    }
};
