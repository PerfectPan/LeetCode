class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += nums[i] == nums[j] and i * j % k == 0;
            }
        }      
        return ans;
    }
};
