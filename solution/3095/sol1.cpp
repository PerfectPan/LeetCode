class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int res = 0;
            for (int j = i; j < nums.size(); ++j) {
                res |= nums[j];
                if (res >= k) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
