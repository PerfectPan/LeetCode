class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = reduce(nums.begin(), nums.end(), 0) - abs(target);
        if (sum < 0 || sum % 2) {
            return 0;
        }
        int n = nums.size();
        int m = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= m; ++c) {
                if (c < nums[i]) {
                    dp[i + 1][c] = dp[i][c];
                } else {
                    dp[i + 1][c] = dp[i][c] + dp[i][c - nums[i]];
                }
            }
        }
        return dp[n][m];
    }
};
