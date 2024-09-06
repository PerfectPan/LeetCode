class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
            for (int kk = 0; kk <= k; ++kk) {
                for (int j = 0; j < i; ++j) {
                    int add = nums[i] != nums[j];
                    if (kk - add >= 0 and dp[j][kk - add] != -1) {
                        dp[i][kk] = max(dp[i][kk], dp[j][kk - add] + 1);
                    }
                }
                ans = max(ans, dp[i][kk]);
            }
        }
        return ans;
    }
};
