class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1, k = n - 1; j < k;) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          j++;
          continue;
        }
        if (nums[i] + nums[j] + nums[k] == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});
          j++;
          k--;
        } else if (nums[i] + nums[j] + nums[k] < 0) {
          j++;
        } else {
          k--;
        }
      }
    }
    return ans;
  }
};
