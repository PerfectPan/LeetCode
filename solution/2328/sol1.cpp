class Solution {
public:
    vector<int> G[100010];
    int p[100010], sz[100010];
    int ans = 0;
    int P = 1e9+7;
    void dfs(int u) {
      if (~sz[u]) {
        return;
      }
      sz[u] = 1;
      for (int i = 0; i < G[u].size(); ++i) {
        int son = G[u][i];
        dfs(son);
        sz[u] = (sz[u] + sz[son]) % P;
      }
      ans = (ans + sz[u]) % P;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int num = n * m;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        memset(sz, -1, sizeof(sz));
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m ;++j) {
            int id = i * m + j;
            for (int k = 0; k < 4; ++k) {
              int tx = i + dx[k];
              int ty = j + dy[k];
              if (tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1 || grid[tx][ty] <= grid[i][j]) continue;
              int pid = tx * m + ty;
              G[id].push_back(pid);
              p[pid] += 1;
            }
          }
        }
        for (int i = 0; i < num; ++i) {
          if (!p[i]) {
            dfs(i);
          }
        }
        return ans;
    }
};

