// dp[i][j] 表示考虑拼完 key 串前 i 个字符，当前 ring 12 点指向 ring[j] 的最小步骤
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        int dp[m + 1][n];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        auto getDis = [&](int x, int y) -> int {
            int len = abs(x - y);
            return min(len, n - len);
        };
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) if (ring[j] == key[i - 1]) {
                for (int k = 0; k < n; ++k) if (~dp[i - 1][k]) {
                    int val = dp[i - 1][k] + 1 + getDis(j, k);
                    if (dp[i][j] == -1) {
                        dp[i][j] = val;
                    } else {
                        dp[i][j] = min(dp[i][j], val);
                    }
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i < n; ++i) if (~dp[m][i]){
            ans = min(ans, dp[m][i]);
        }
        return ans;
    }
};
