class Solution {
public:
    using ll = long long;
    int minimumPartition(string s, int k) {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        vector<int> pw(11);
        dp[0] = 0;
        pw[0] = 1;
        for (int i = 1; i <= 9; ++i) {
            pw[i] = pw[i - 1] * 10;
        }
        for (int i = 1; i <= n; ++i) {
            ll num = 0;
            for (int j = 1; i - j >= 0 && j <= 10; ++j) {
                if (dp[i - j] == -1) {
                    continue;
                }
                num += 1LL * (s[i - j] - '0') * pw[j - 1];
                if (num <= k) {
                    if (dp[i] == -1) {
                        dp[i] = dp[i - j] + 1;
                    } else {
                        dp[i] = min(dp[i], dp[i - j] + 1);
                    }
                } else {
                    break;
                }
            }
        }
        return dp[n];
    }
};
