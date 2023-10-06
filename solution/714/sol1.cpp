// dp[0][i] 表示到第 i 天手里持有一支股票的最大利润
// dp[1][i] 表示到第 i 天手里不持有股票的最大利润
// 时间复杂度 O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[2][n];
        dp[0][0] = -prices[0];
        dp[1][0] = 0;
        for (int i = 1; i < n; ++i) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i] + prices[i] - fee);
        }
        return dp[1][n - 1];
    }
};
