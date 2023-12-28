class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums.push_back(nums[i]);
        }
        int mn[n][n];
        for (int i = 0; i < n; ++i) {
            mn[i][0] = nums[i];
            for (int j = 1; j < n; ++j) {
                mn[i][j] = min(mn[i][j - 1], nums[i + j]);
            }
        }
        long long ans = 1e18;
        for (int i = 0; i < n; ++i) {
            long long res = 1LL * x * i;
            for (int j = 0; j < n; ++j) {
                res += mn[j][i];
            }
            ans = min(ans, res);
        }
        return ans;
    }
};
