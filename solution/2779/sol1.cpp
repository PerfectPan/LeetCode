class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, l = 0;

        for (int r = 0; r < nums.size(); ++r) {
            while (nums[r] - nums[l] > k * 2) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
