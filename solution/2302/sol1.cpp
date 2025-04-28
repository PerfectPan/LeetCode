class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
        }
        long long ans = 0;
        for (int l = 0, r = 0; l < n; ++l) {
            for (; r < n and (pre[r + 1] - pre[l]) * (r - l + 1) < k; r++);

            ans += r - l;
        }

        return ans;
    }
};
