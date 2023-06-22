// 状压 DP，dp[i][j] 表示当前集合为 i，排列最后一位为 nums[j] 的排列数目，转移枚举 j 即可
// 时间复杂度 O(n^2 2^n)
class Solution {
public:
    int P = 1e9 + 7;
    void add(int& a, int b) {
        a += b;
        if (a >= P) a -= P;
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        int dp[1 << n][n];
        bool vis[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vis[i][j] = nums[i] % nums[j] == 0;
            }
        }
        memset(dp, 0, sizeof (dp));
        int S = 1 << n;
        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = 1;
        }
        for (int i = 1; i < S; ++i) {
            if (__builtin_popcount(i) <= 1) {
                continue;
            }
            for (int j = 0; j < n; ++j) if (i & (1 << j)){
                for (int k = 0; k < n; ++k) if ((i & (1 << k)) and (j != k)) {
                    if (vis[j][k] or vis[k][j]) {
                        add(dp[i][j], dp[i ^ (1 << j)][k]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            add(ans, dp[S - 1][i]);
        }
        return ans;
    }
};
