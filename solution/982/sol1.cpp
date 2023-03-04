// f[i] 表示 i 的子集的数量，SOS DP https://codeforces.com/blog/entry/45223
// 双重枚举前两位 i 和 j，第三位合法的数量即为 f[(nums[i] & nums[j]) ^ ((1 << total - 1)
// O(n^2 + C * 2^C) 这里 C = 16
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int total = 16;
        vector<int>f(1 << total, 0);
        for (int& num: nums) {
            f[num] += 1;
        }
        for (int i = 0; i < total; ++i) {
            for (int mask = 0; mask < (1 << total); ++mask) {
                if (mask & (1 << i)) {
                    f[mask] += f[mask ^ (1 << i)];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                int ret = (nums[i] & nums[j]) ^ ((1 << total) - 1);
                ans += f[ret];
            }
        }   
        return ans;
    }
};
