class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int dp = 0, ans = INT_MIN;
    for (auto& x : nums) {
      dp = max(x, dp + x);
      ans = max(ans, dp);
    }
    return ans;
  }
};
