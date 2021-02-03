class Solution {
public:
  void dfs(int u, int f, vector<int> &ans, vector<vector<int>> &G) {
    ans.emplace_back(u - 100000);
    for (int &v : G[u]) {
      if (v == f)
        continue;
      dfs(v, u, ans, G);
    }
  }
  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    int n = adjacentPairs.size() + 1;
    vector<vector<int>> G(200001, vector<int>{});
    vector<int> deg(200001, 0);
    for (auto &vec : adjacentPairs) {
      int x = vec[0] + 100000, y = vec[1] + 100000;
      G[x].emplace_back(y);
      G[y].emplace_back(x);
      deg[x] += 1;
      deg[y] += 1;
    }
    int st = -1;
    for (int i = 0; i < 200001; ++i) {
      if (deg[i] == 1) {
        st = i;
      }
    }
    vector<int> ans;
    dfs(st, -1, ans, G);
    return ans;
  }
};
