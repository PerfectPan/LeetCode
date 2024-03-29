class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] < nums[j] and nums[k] < nums[j]) {
                        int v = nums[i] + nums[j] + nums[k];
                        ans = ans == -1 ? v : min(ans, v);
                    }
                }
            }
        }
        return ans;
    }
};
