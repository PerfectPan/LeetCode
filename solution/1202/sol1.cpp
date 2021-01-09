class Solution {
public:
  int fa[100010];
  int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    int n = s.size();
    for (int i = 0; i < n; ++i)
      fa[i] = i;
    for (int i = 0; i < pairs.size(); ++i) {
      int x = pairs[i][0], y = pairs[i][1];
      int ux = Find(x), uy = Find(y);
      if (ux ^ uy) {
        fa[ux] = uy;
      }
    }
    vector<vector<char>> vec(n, vector<char>{});
    for (int i = 0; i < n; ++i) {
      fa[i] = Find(i);
      vec[fa[i]].emplace_back(s[i]);
    }
    for (int i = 0; i < n; ++i) {
      if (vec[i].size() > 0) {
        sort(vec[i].begin(), vec[i].end());
      }
    }
    vector<int> p(n, 0);
    string ans;
    for (int i = 0; i < n; ++i)
      ans += '1';
    for (int i = 0; i < n; ++i) {
      ans[i] = vec[fa[i]][p[fa[i]]];
      p[fa[i]]++;
    }
    return ans;
  }
};
