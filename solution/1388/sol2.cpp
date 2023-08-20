// 问题等价成为给一个长度为 3n 的环状序列，你可以在其中选择 n 个数，并且任意两个数不能相邻，求这 n 个数的最大值。
// 先不考虑环形，可以直接 dp，dp[i][j] 表示前 i 个数选 j 个不相邻的数的最大值，转移要么当前数选，要么不选
// 然后环状序列相较于普通序列，相当于添加了一个限制：普通序列中的第一个和最后一个数不能同时选。
// 这样一来，我们只需要对普通序列进行两遍动态即可得到答案，第一遍动态规划中我们删去普通序列中的第一个数，表示我们不会选第一个数；
// 第二遍动态规划中我们删去普通序列中的最后一个数，表示我们不会选最后一个数。将这两遍动态规划得到的结果去较大值，即为在环状序列上的答案。
// 时间复杂度 O(n^2)
class Solution {
public:
    int cal(const vector<int>& slices) {
        int N = slices.size(), n = (N + 1) / 3;
        vector<vector<int>> dp(n + 1, vector<int>(N, INT_MIN));
        dp[0][0] = 0;
        dp[1][0] = slices[0];
        dp[0][1] = 0;
        dp[1][1] = max(slices[0], slices[1]);
        for (int i = 2; i < N; ++i) {
            dp[0][i] = 0;
            for (int k = 1; k <= n; ++k) {
                dp[k][i] = max(dp[k][i - 1], dp[k - 1][i - 2] + slices[i]);
            }
        }
        return dp[n][N - 1];
    }
    int maxSizeSlices(vector<int>& slices) {
        vector<int> v1(slices.begin() + 1, slices.end());
        vector<int> v2(slices.begin(), slices.end() - 1);
        return max(cal(v1), cal(v2));
    }
};
