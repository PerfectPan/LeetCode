class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(51, 0);
        vector<int> pre(n + 1, 0);
        int suff = 0;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i];
            if (++cnt[nums[i]] == 1) {
                pre[i + 1] += 1;
            }
        }
        for (int i = 0; i < 51; ++i) {
            cnt[i] = 0;
        }
        vector<int> ans(n, 0);
        ans[n - 1] = pre[n];
        for (int i = n - 1; i >= 1; --i) {
            if (++cnt[nums[i]] == 1) {
                suff++;
            }
            ans[i - 1] = pre[i] - suff;
        }
        return ans;
    }
};
