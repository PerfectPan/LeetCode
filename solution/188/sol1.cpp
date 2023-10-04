// dp[0][j][i] 表示到第 i 天，恰好交易 j + 1 次，且手上持有一支股票的最大利润
// dp[1][j][i] 表示到第 i 天，恰好交易 j + 1 次，且手上不持有股票的最大利润
// 转移即可，最后答案为 dp[1][0..k-1][i-1] 的最大值
// 初始值的设定考虑当天可以重复买入买出股票，所以 dp[0][0..k-1][0] 均为 -prices[0]（前 x 次都是买入就卖出了，这一次买入的时候利润就是 -prices[0]）, dp[1][0..k-1][0] 均为 0
// 时间复杂度 O(nk)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[2][k][n];
        for (int i = 0; i < k; ++i) {
            dp[0][i][0] = -prices[0];
            dp[1][i][0] = 0;
        }

        for (int i = 1; i < n; ++i) {
            dp[0][0][i] = max(dp[0][0][i - 1], -prices[i]);
            dp[1][0][i] = max(dp[1][0][i - 1], dp[0][0][i] + prices[i]);
            for (int j = 1; j < k; ++j) {
                dp[0][j][i] = max(dp[0][j][i - 1], dp[1][j - 1][i - 1] - prices[i]);
                dp[1][j][i] = max(dp[1][j][i - 1], dp[0][j][i] + prices[i]);
            }
        }

        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans = max(ans, dp[1][i][n - 1]);
        }
        return ans;
    }
};
