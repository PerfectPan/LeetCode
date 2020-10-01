class Solution {
public:
  vector<int> ans, sz, dp;
  vector<vector<int>> G;
  void dfs(int u, int f) {
    sz[u] = 1;
    dp[u] = 0;
    for (auto &v : G[u]) {
      if (v == f)
        continue;
      dfs(v, u);
      dp[u] += dp[v] + sz[v];
      sz[u] += sz[v];
    }
  }
  void dfs2(int u, int f) {
    ans[u] = dp[u];
    for (auto &v : G[u]) {
      if (v == f)
        continue;
      int pu = dp[u], pv = dp[v];
      int su = sz[u], sv = sz[v];

      dp[u] -= dp[v] + sz[v];
      sz[u] -= sz[v];
      sz[v] += sz[u];
      dp[v] += dp[u] + sz[u];

      dfs2(v, u);

      dp[u] = pu, dp[v] = pv;
      sz[u] = su, sz[v] = sv;
    }
  }
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
    ans.resize(N, 0);
    sz.resize(N, 0);
    dp.resize(N, 0);
    G.resize(N, {});
    for (auto &edge : edges) {
      int u = edge[0], v = edge[1];
      G[u].emplace_back(v);
      G[v].emplace_back(u);
    }
    dfs(0, -1);
    dfs2(0, -1);
    return ans;
  }
};