class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int ans = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i + 1 < nums.size(); ++i) {
          int L = i + 1, R = (int)nums.size() - 1, res = -1;
          while (L <= R) {
            int mid = (L + R) / 2;
            if (nums[mid] + nums[i] <= target) {
              R = mid - 1;
              res = mid;
            } else {
              L = mid + 1;
            }
          }
          if (~res) {
            ans = (ans + (int)nums.size() - 1 - res + 1) % MOD;
          }
        }
        return ans;
    }
};

