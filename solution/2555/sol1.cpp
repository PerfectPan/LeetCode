class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        for (int i = 1; i <= n; ++i) {
            int l = 1, r = i, res = -1;
            while (l <= r) {
                int mid = l + ((r - l) >> 1);
                if (prizePositions[i - 1] - prizePositions[mid - 1] <= k) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            if (res != -1) {
                dp[i][0] = max(dp[i][0], i - res + 1);
                dp[i][1] = max(dp[i][1], dp[res - 1][0] + i - res + 1);
            }
        }
        return dp[n][1];
    }
};
