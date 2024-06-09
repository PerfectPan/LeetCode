// dp[i][j] 表示开区间 (i, j) 的最大硬币数量，枚举最后一个被击破的气球 k，那么这次击破的收益为 nums[i] * nums[k] * nums[j]，剩余两个区间递归计算下去
// 因此转移方程为 dp[i][j] = max{ nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j] }
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; ++i) {
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n + 1; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], val[i] * val[k] * val[j] + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][n + 1];
    }
};
