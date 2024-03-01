// f[i] 表示到 i 结尾是否存在有效划分，根据题意，枚举前两个和前三个是否可以划分，转移即可
// 时间复杂度 O(n)
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        f[0] = true;
        for (int i = 0; i < n; ++i) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                f[i + 1] |= f[i - 1];
            }
            if (i - 2 >= 0 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
                f[i + 1] |= f[i - 2];
            }

            if (i - 2 >= 0 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) {
                f[i + 1] |= f[i - 2];
            }
        }
        return f[n];
    }
};
