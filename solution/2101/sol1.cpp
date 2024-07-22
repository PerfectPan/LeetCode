class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> f(n, vector<int>(n, 0));

        auto ok = [&](int x, int y) -> bool {
            return 1LL * (bombs[x][0] - bombs[y][0]) * (bombs[x][0] - bombs[y][0]) + 1LL * (bombs[x][1] - bombs[y][1]) * (bombs[x][1] - bombs[y][1]) <= 1LL * bombs[x][2] * bombs[x][2];
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i][j] = ok(i, j);
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) if (i != k) {
                for (int j = 0; j < n; ++j) if (i != j && j != k) {
                    f[i][j] |= f[i][k] && f[k][j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = 0; j < n; ++j) {
                res += f[i][j];
            }
            ans = max(ans, res);
        }

        return ans;
    }
};
