// 贪心倒着合并一轮就好了，如果 nums[i] 比之前合并起来的数都要大，那就从 i 开始继续合并
// 时间复杂度 O(n)
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long mx = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > mx) {
                mx = nums[i];
            } else {
                mx = mx + nums[i];
            }
        }
        return mx;
    }
};
