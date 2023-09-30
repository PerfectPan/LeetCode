// 枚举每个塔为山峰，设它向左延伸高度和最大值为 f_i，向右延伸高度和最大值为 g_i，答案即为 f_i + g_i - maxHeights_i，取最大值即可
// 假设此时已经算出 [1..i - 1] 的答案 f，那么对于塔 i 来说向左找第一个比它小的位置 j，此时 [j + 1, i - 1] 的塔的最高高度都大于 i，我们把它们的高度都改成和山峰一样，那么答案 f_i = f_j + (i - j) * maxHeights_i
// 向左找第一个比它小的位置这个问题用单调栈解决即可
// 向右延伸同理
// 时间复杂度 O(n)
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();

        auto gao = [&](vector<long long>& f) {
            stack<int> stk;
            for (int i = 0; i < n; ++i) {
                while (!stk.empty() && maxHeights[stk.top()] >= maxHeights[i]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    f[i] = 1LL * maxHeights[i] * (i + 1);
                } else {
                    f[i] = f[stk.top()] + 1LL * maxHeights[i] * (i - stk.top());
                }
                stk.push(i);
            }
        };

        vector<long long> f(n);
        gao(f);
        vector<long long> g(n);
        reverse(maxHeights.begin(), maxHeights.end());
        gao(g);
        reverse(maxHeights.begin(), maxHeights.end());

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i] + g[n - 1 - i] - maxHeights[i]);
        }
        return ans;
    }
};
