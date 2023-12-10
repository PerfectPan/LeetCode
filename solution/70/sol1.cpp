class Solution {
public:
    int climbStairs(int n) {
        int dp_0 = 0, dp_1 = 1, dp;
        for (int i = 1; i <= n; ++i) {
            dp = dp_0 + dp_1;
            dp_0 = dp_1;
            dp_1 = dp;
        }
        return dp;
    }
};
