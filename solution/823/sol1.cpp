// 排序以后 dp 显然，dp[i] 表示以 arr[i] 为根结点的方案数，从满足 arr[l] * arr[r] = arr[i] 的 (l, r)，转移过来，如果 l == r dp[i] += dp[l] * dp[r] 否则 dp[i] += 2 * dp[l] * dp[r]
// 找满足条件的 l 和 r 可以用双指针找，把复杂度降到线性
// 时间复杂度 O(n^2)
class Solution {
public:
    int P = 1e9 + 7;
    void add(int& a, int b) { a += b; if (a >= P) a -= P; }
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            dp[i] = 1;
            for (int l = 0, r = i - 1; l <= r; l += 1) {
                while (r >= l && 1LL * arr[l] * arr[r] > arr[i]) {
                    r -= 1;
                }
                if (r >= l && 1LL * arr[l] * arr[r] == arr[i]) {
                    add(dp[i], (l == r ? 1LL : 2LL) * dp[l] * dp[r] % P);
                }
            }
            add(ans, dp[i]);
        }
        return ans;
    }
};
