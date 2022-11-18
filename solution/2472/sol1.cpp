class Solution {
public:
    bool isPa[2005][2005];
    int maxPalindromes(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            isPa[i][i] = true;
            if (i + 1 < n) {
                isPa[i][i + 1] = s[i] == s[i + 1];
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int l = 0; l + len - 1 < n; ++l) {
                int r = l + len - 1;
                isPa[l][r] = isPa[l + 1][r - 1] && (s[l] == s[r]);
            }
        }
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            if (i - k >= 0 && isPa[i - k][i - 1]) {
                dp[i] = max(dp[i - k] + 1, dp[i]);
            }
            if (i - k - 1 >= 0 && isPa[i - k - 1][i - 1]) {
                dp[i] = max(dp[i - k - 1] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};
