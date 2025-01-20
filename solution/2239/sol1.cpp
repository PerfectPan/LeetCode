class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int x : nums) {
            if (abs(x) < abs(ans) || abs(x) == abs(ans) && x > 0) {
                ans = x;
            }
        }
        return ans;
    }
};
