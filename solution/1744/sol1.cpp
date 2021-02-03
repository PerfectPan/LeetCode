class Solution {
public:
  vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
    vector<long long> prefix;
    prefix.emplace_back(0);
    for (int &candies : candiesCount) {
      prefix.emplace_back(candies + prefix.back());
    }
    vector<bool> ans;
    for (auto &vec : queries) {
      int f = vec[0] + 1, d = vec[1], cap = vec[2];
      long long mn = d + 1, mx = 1LL * cap * (d + 1);
      ans.emplace_back((mx <= prefix[f] && mx > prefix[f - 1]) ||
                       (prefix[f] >= mn && mx > prefix[f]));
    }
    return ans;
  }
};
