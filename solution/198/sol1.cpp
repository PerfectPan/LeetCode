class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (!n) return 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];
            if (i >= 2) dp[i] = max(dp[i], dp[i - 2] + nums[i]);
            else dp[i] = max(dp[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

