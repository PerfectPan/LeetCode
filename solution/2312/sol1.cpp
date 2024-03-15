// dp[m][n] 表示切 (m, n) 的木块能得到的最大价值，枚举横着切和竖着切即可，可以分成两个子问题
// 一个优化是只要枚举一半即可，比如 [1, m - 1] 个可以切的位置，我只要切 [1, m / 2] 即可
// 因为后面切出来的木块重复了，比如你在 1 位置切一刀得到 (1, n) 和 (m - 1, n)，那么你在 m - 1 切一刀的时候得到 (m - 1, n) 和 (1, n)
// 与在 1 位置切的是等效的，因此不用再枚举
// 时间复杂度 O(mn(m + n))
class Solution {
public:
    using ll = long long;
    ll dp[205][205];
    ll p[205][205];
    ll dfs(int m, int n) {
        if (~dp[m][n]) {
            return dp[m][n];
        }
        ll ret = ~p[m][n] ? p[m][n] : 0;
        for (int i = 1; i <= m / 2; ++i) {
            ll up = dfs(i, n);
            ll down = dfs(m - i, n);
            ret = max(ret, up + down);
        }

        for (int i = 1; i <= n / 2; ++i) {
            ll left = dfs(m, i);
            ll right = dfs(m, n - i);
            ret = max(ret, left + right);
        }

        return dp[m][n] = ret;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        memset(dp, -1, sizeof(dp));
        memset(p, -1, sizeof(p));
        for (const auto& price: prices) {
            p[price[0]][price[1]] = price[2];
        }
        return dfs(m, n);
    }
};
