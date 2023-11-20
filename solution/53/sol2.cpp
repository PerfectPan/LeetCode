// 数组和看成两个前缀和相减
// 从前往后枚举下标 i，维护到 i 的前缀和，现在要找这以下标 i 结尾的最大子数组和
// 等价于 [1..i-1] 找一个最小前缀和，这样相减才会最大
// 因此再用一个变量维护最小前缀和 pre_mn，下标 i 的答案就是 sum - pre_mn
// 最后的结果就是所有下标的答案取 max
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, pre_mn = 0, ans = INT_MIN;
        for (int& num: nums) {
            sum += num;
            ans = max(ans, sum - pre_mn);
            pre_mn = min(pre_mn, sum);
        }
        return ans;
    }
};
