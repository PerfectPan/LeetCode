class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double ans = 100;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            ans = min(ans, 1.0 * (nums[i] + nums[j]) / 2);
        }
        return ans;   
    }
};
