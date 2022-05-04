class Solution {
public:
    int dp[100010];
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        memset(dp, -0x3f3f3f3f, sizeof(dp));
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + stones[i];
        }
        dp[n - 1] = pre[n];
        for (int i = n - 2; i >= 1; --i) {
            dp[i] = max(dp[i + 1], pre[i + 1] - dp[i + 1]);
        }
        return dp[1];
    }
};

