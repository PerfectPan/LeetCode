// DP，状态定义已经写在下面注释里了
// 时间复杂度 O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[3][n];
        // 持有一支
        dp[0][0] = -prices[0];
        // 不持有且在冷冻期
        dp[1][0] = 0;
        // 不持有且不在冷冻期
        dp[2][0] = 0;
        for (int i = 1; i < n; ++i) {
            dp[0][i] = max(dp[0][i - 1], dp[2][i - 1] - prices[i]);
            dp[1][i] = dp[0][i] + prices[i];
            dp[2][i] = max(dp[1][i - 1], dp[2][i - 1]);
        }

        return max(dp[1][n - 1], dp[2][n - 1]);
    }
};
