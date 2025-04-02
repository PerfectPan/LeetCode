class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = max(prefix[i], nums[i]);
        }
        int mx = nums[n - 1];
        for (int i = n - 2; i >= 1; --i) {
            ans = max(ans, 1LL * (prefix[i] - nums[i]) * mx);
            mx = max(mx, nums[i]);
        }
        return ans;
    }
};
