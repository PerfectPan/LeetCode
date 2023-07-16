// 贪心模拟，从前往后尽可能的将元素减为 0，然后看是否都能减成 0 即可
// 题解是先求出差分数组，然后差分数组的性质就是能将区间加变成单点加和单点减，从而将复杂度降下来
class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) {
            return true;
        }
        int add = nums[0];
        vector<int> flags(n + 1, 0);
        flags[k] = add;
        for (int i = 1; i < n; ++i) {
            add -= flags[i];
            nums[i] -= add;
            if (nums[i] < 0) {
                return false;
            }
            add += nums[i];
            if (i + k <= n) {
                flags[i + k] += nums[i];
            }
        }
        return nums[n - 1] == 0;
    }
};
