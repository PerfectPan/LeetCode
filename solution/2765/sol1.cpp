class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        int i = 0;
        while (i + 1 < n) {
            if (nums[i + 1] - nums[i] != 1) {
                i++;
                continue;
            }
            int r = i + 1, op = 1;
            for (; r < n && nums[r] - nums[r - 1] == op; ++r, op = -op);
            ans = max(ans, r - i);
            i = r - 1;
        }
        return ans;
    }
};
