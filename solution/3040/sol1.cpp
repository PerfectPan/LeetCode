// 枚举是删除哪两个数，和为 x，然后问题就变成一个数组最多可以删几个 x，区间 dp 即可
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        auto check = [&](int x) -> int {
            vector<vector<int>> dp(n, vector<int>(n, 0));
            for (int i = 2; i <= n; ++i) {
                for (int l = 0; l + i <= n; ++l) {
                    int r = l + i - 1;
                    if (r - l == 1) {
                        dp[l][r] = nums[l] + nums[r] == x;
                    } else {
                        if (nums[l] + nums[l + 1] == x) {
                            dp[l][r] = max(dp[l][r], dp[l + 2][r] + 1);
                        }
                        if (nums[r - 1] + nums[r] == x) {
                            dp[l][r] = max(dp[l][r], dp[l][r - 2] + 1);
                        }
                        if (nums[l] + nums[r] == x) {
                            dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 1);
                        }
                    }
                }
            }
            return dp[0][n - 1];
        };

        return max({ check(nums[0] + nums[1]), check(nums[0] + nums.back()), check(nums[n - 2] + nums[n - 1]) });
    }
};
