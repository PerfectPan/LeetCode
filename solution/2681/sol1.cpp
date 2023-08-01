// 排序，枚举每个数作为最大值时符合条件的子集最小值和是多少
// 然后排列组合计算即可，就是我们枚举位置 i 为最小值，当前在枚举 j，那么可选的就是 j - i - 1 中间的数，然后你算一下前缀和发现是 a_0 * 2^x + a_1 * 2^(x - 1) + ...
// 如果是在枚举 j + 1，发现就是 a_0 * 2^{x + 1} + a_1 * 2^x + ...
// 所以每次往后枚举的时候这个前缀和要乘一个 2 就行了
// 官方题解是动态规划，也差不多
class Solution {
public:
    int P = 1e9 + 7;
    void up(int& a, int b) { a += b; if (a >= P) a -= P; }
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;

        up(ans, 1LL * nums[0] * nums[0] % P * nums[0] % P);
        if (nums.size() == 1) {
            return ans;
        }
        up(ans, 1LL * (nums[0] + nums[1]) * nums[1] % P * nums[1] % P);

        int pre = nums[0];
        for (int i = 2; i < nums.size(); ++i) {
            pre = 2LL * pre % P;
            up(pre, nums[i - 1]);
            int temp = pre;
            up(temp, nums[i]);
            up(ans, 1LL * temp * nums[i] % P * nums[i] % P);
        }
        return ans;
    }
};
