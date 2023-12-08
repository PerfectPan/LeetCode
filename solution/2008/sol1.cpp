class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int mx = 0;
        for (auto& ride: rides) {
            mx = max(mx, ride[1]);
        }
        vector<long long> dp(mx + 1, 0);
        vector<vector<pair<int, int>>> ed(mx + 1);
        for (auto& ride: rides) {
            int s = ride[0], e = ride[1], tip = ride[2];
            ed[e].push_back({ s, e - s + tip });
        }
        for (int i = 1; i <= mx; ++i) {
            dp[i] = dp[i - 1];
            for (auto& [s, fee]: ed[i]) {
                dp[i] = max(dp[i], dp[s] + fee);
            }
        }
        return dp[mx];
    }
};
