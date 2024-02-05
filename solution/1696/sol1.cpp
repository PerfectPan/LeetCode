class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        multiset<int, greater<int>> S;
        int n = nums.size();
        vector<int> dp(n, -1e9);
        dp[0] = nums[0];
        S.insert(dp[0]);
        for (int i = 1; i < n; ++i) {
            if (i - k - 1 >= 0) {
                auto it = S.find(dp[i - k - 1]);
                S.erase(it);
            }
            dp[i] = nums[i] + (*S.begin());
            S.insert(dp[i]);
        }
        return dp[n - 1];
    }
};
