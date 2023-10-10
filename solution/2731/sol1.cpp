// 碰撞其实可以看成穿透，原本左边的机器人相撞后交换为右边的机器人，原本右边的机器人相撞后交换为左边的机器人，这样一来，两个机器人仿佛没有相撞过
// 所以直接无视碰撞，计算 d 秒后的位置即可，算完以后排序统计答案即可
// 统计答案也有一种方案是考虑每段距离 d_i 被几对机器人算到了，考虑左右这段距离左右几个机器人 a 和 n - a，然后乘一下就好了 a * (n - a) * d_i
class Solution {
public:
    using ll = long long;
    int sumDistance(vector<int>& nums, string s, int d) {
        int P = 1e9 + 7;
        int n = nums.size();
        vector<ll> res(n, 0);
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = nums[i] + d * (s[i] == 'R' ? 1 : -1);
        }
        sort(res.begin(), res.end());

        ll ans = 0, pre = 0;        
        for (int i = 1; i < n; ++i) {
            pre = (pre + (res[i] - res[i - 1]) * i % P) % P;
            ans = (ans + pre) % P;
        }
        return ans;
    }
};
