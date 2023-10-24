// dp[i][j] 表示投了 i 个骰子，总和为 j 的方案数
// 时间复杂度 O(n * k * target)
class Solution {
public:
    int P = 1e9 + 7;
    void up(int& a, int b) { a += b; if (a >= P) a -= P; }
    int numRollsToTarget(int n, int k, int target) {
        int dp[n + 1][target + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= min(k, target); ++i) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int S = j + 1; S <= target; ++S) {
                    up(dp[i][S], dp[i - 1][S - j]);
                }
            }
        }
        return dp[n][target];
    }
};
