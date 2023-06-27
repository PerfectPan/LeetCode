// 维护以 i 为末尾的最大前缀和，以 i 为开始的最大前缀和，枚举分割点 i 算答案即可
// 时间复杂度 O(n)
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n + 1, -1e9);
        vector<int> suff(n + 1, -1e9);
        pre[0] = suff[n] = 0;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = max(arr[i], pre[i] + arr[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = max(arr[i], suff[i + 1] + arr[i]);
        }
        int ans = -1e9;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ans = max(ans, suff[i]);
            } else if (i == n - 1) {
                ans = max(ans, pre[i + 1]);
            } else {
                ans = max(ans, pre[i] + suff[i + 1]);
                ans = max(ans, pre[i + 1] + suff[i + 1]);
            }
        }
        return ans;
    }
};
