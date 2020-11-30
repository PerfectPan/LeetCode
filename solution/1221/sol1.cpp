class Solution {
public:
  int balancedStringSplit(string s) {
    int ans = 0;
    int cnt = 0;
    for (auto &ch : s) {
      cnt += ch == 'L' ? 1 : -1;
      ans += cnt == 0;
    }
    return ans;
  }
};
