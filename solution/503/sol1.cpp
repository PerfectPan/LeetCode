class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_tmp(n * 2);
        for (int i = 0; i < 2 * n; ++i) {
            nums_tmp[i] = nums[i >= n ? i - n : i];
        }
        vector<int> stack;
        vector<int> ans(n, -1);
        for (int i = 2 * n - 1; i >= n; --i) {
            while (stack.size() > 0 and stack.back() <= nums_tmp[i]) {
                stack.pop_back();
            }
            stack.push_back(nums_tmp[i]);
        }

        for (int i = n - 1; i >= 0; --i) {
            while (stack.size() > 0 and stack.back() <= nums_tmp[i]) {
                stack.pop_back();
            }
            if (stack.size() > 0) {
                ans[i] = stack.back();
            }
            stack.push_back(nums_tmp[i]);
        }

        return ans;
    }
};
