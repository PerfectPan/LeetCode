class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums[0][0], r = nums[0][1];
        int idx = 1, ans = 0;
        while (idx < nums.size()) {
            if (nums[idx][0] <= r) {
                r = max(r, nums[idx][1]);
            } else {
                ans += r - l + 1;
                l = nums[idx][0];
                r = nums[idx][1];
            }
            idx++;
        }
        ans += r - l + 1;
        return ans;
    }
};
