class Solution {
public:
  bool vis[128];
  int numJewelsInStones(string J, string S) {
    int ans = 0;
    for (auto &ch : J) {
      vis[ch] = true;
    }
    for (auto &ch : S) {
      ans += vis[ch];
    }
    return ans;
  }
};