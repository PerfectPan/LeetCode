class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int f[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i][j] = 1e9;
            }
        }
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            f[u][v] = f[v][u] = w;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        int ans = 1e9, id = -1;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) if (i != j) {
                cnt += f[i][j] <= distanceThreshold;
            }
            if (ans >= cnt) {
                ans = cnt;
                id = i;
            }
        }
        return id;
    }
};
