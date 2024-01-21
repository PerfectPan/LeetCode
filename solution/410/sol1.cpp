// dp[i][k] 表示前 i 个数字划分 k 个子数组各自和最大值的最小值
// 转移枚举划分位置 j，时间复杂度 O(n^2 * m)
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n + 1][k + 1];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        int pre[n + 1];
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                for (int _k = 1; _k <= k; _k++) if (dp[j - 1][_k - 1] != -1) {
                    if (dp[i][_k] == -1) {
                        dp[i][_k] = max(dp[j - 1][_k - 1], pre[i] - pre[j - 1]);
                    } else {
                        dp[i][_k] = min(dp[i][_k], max(dp[j - 1][_k - 1], pre[i] - pre[j - 1]));
                    }
                }
            }
        }
        return dp[n][k];
    }
};
