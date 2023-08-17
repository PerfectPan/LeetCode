// dp[i][j][k] 表示以 (i, j) 为左上角顶点的 pizza 切 k 刀的可行方案数
// 转移枚举横着切还是竖着切即可，下面代码写复杂了，应该直接算 sum[i][j] 表示以 (i, j) 为左上角顶点的苹果数
// 然后也不用写递归，直接 for 循环即可，for k for x for y { 枚举横着切 | 美剧竖着切 }
// 时间复杂度 O(knm(n + m))
class Solution {
public:
    int P = 1e9 + 7;
    int sum[55][55];
    int dp[55][55][11];
    int n, m;
    void add(int& a, int b) { a += b; if (a >= P) a -= P; }
    int getApple(int x1, int y1, int x2, int y2) {
        return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
    }
    int f(int x, int y, vector<string>& pizza, int k) {
        if (~dp[x][y][k]) {
            return dp[x][y][k];
        }
        if (!k) {
            return dp[x][y][k] = getApple(x, y, n, m) > 0;
        }
        int ret = 0;
        for (int i = x; i < n; ++i) {
            int up = getApple(x, y, i, m);
            int down = getApple(i + 1, y, n, m);
            if (up > 0 && down > 0) {
                add(ret, f(i + 1, y, pizza, k - 1));
            }
        }

        for (int j = y; j < m; ++j) {
            int left = getApple(x, y, n, j);
            int right = getApple(x, j + 1, n, m);
            if (left > 0 && right > 0) {
                add(ret, f(x, j + 1, pizza, k - 1));
            }
        }
        return dp[x][y][k] = ret;
    }
    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof(dp));
        n = pizza.size(), m = pizza[0].size();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');
            }
        }
        return f(1, 1, pizza, k - 1);
    }
};
