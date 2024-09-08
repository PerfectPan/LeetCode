class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, p = n - 1; i <= j; --p) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                ans[p] = nums[j] * nums[j];
                j--;
            } else {
                ans[p] = nums[i] * nums[i];
                i++;
            }
        }
        return ans;
    }
};
