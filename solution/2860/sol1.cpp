class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = nums[0] > 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 > nums[i] and (i + 1 == n or nums[i + 1] > i + 1)) {
                ans++;
            }
        }
        return ans;
    }
};
