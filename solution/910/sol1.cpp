class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums[nums.size() - 1] - nums[0];
        for (int i = 0; i + 1 < nums.size(); ++i) {
            int a = nums[i] + k;
            int b = nums[nums.size() - 1] - k;
            int c = nums[i + 1] - k;
            int d = nums[0] + k;

            ans = min(ans, max({a, b, c, d}) - min({a, b, c, d}));
        }

        return ans;
    }
};
