// 贪心，假如 x < y，那么一定是把 x 可以填到 y 上的都往 y 上填会让答案变大
// 所以按位统计以后，构造前 k 大个数字即可
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> cnt(32, 0);
        for (int num: nums) {
            for (int i = 0; i < 32; ++i) {
                if (num & (1 << i)) {
                    cnt[i]++;
                }
            }
        }
        int ans = 0, P = 1e9 + 7;
        for (int _ = 1; _ <= k; ++_) {
            int num = 0;
            for (int i = 0; i < 32; ++i) {
                if (cnt[i] > 0) {
                    num |= 1 << i;
                    cnt[i]--;
                }
            }
            ans = (ans + 1LL * num * num % P) % P;
        }
        return ans;
    }
};
