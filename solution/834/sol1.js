let ans, sz, dp, G;
const dfs = (u, f) => {
  sz[u] = 1;
  dp[u] = 0;
  for (const v of G[u]) {
    if (v === f) continue;
    dfs(v, u);
    dp[u] += dp[v] + sz[v];
    sz[u] += sz[v];
  }
}
const dfs2 = (u, f) => {
  ans[u] = dp[u];
  for (const v of G[u]) {
    if (v === f) continue;
    const pu = dp[u], pv = dp[v];
    const su = sz[u], sv = sz[v];

    dp[u] -= dp[v] + sz[v];
    sz[u] -= sz[v];
    sz[v] += sz[u];
    dp[v] += dp[u] + sz[u];

    dfs2(v, u);

    dp[u] = pu, dp[v] = pv;
    sz[u] = su, sz[v] = sv;
  }
}
var sumOfDistancesInTree = function (N, edges) {
  ans = new Array(N).fill(0);
  sz = new Array(N).fill(0);
  dp = new Array(N).fill(0);
  G = new Array(N).fill(0).map(v => []);
  for (const [u, v] of edges) {
    G[u].push(v);
    G[v].push(u);
  }
  dfs(0, -1);
  dfs2(0, -1);
  return ans;
};