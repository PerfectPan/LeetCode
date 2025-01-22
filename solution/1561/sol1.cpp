class Solution {
public:
    int maxCoins(vector<int>& piles) {
      int ans = 0;
      sort(piles.begin(), piles.end());
      reverse(piles.begin(), piles.end());
      int cnt = piles.size() / 3;
      for (int i = 0; i < cnt * 2; i += 2) {
        ans += piles[i + 1];
      }
      return ans;
    }
};
