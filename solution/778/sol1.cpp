class Solution {
public:
  int dir_x[4] = {0, 1, 0, -1};
  int dir_y[4] = {1, 0, -1, 0};
  int Find(int x, vector<int> &fa) {
    return x == fa[x] ? x : fa[x] = Find(fa[x], fa);
  }
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mx = max(mx, grid[i][j]);
      }
    }
    int L = 0, R = mx, ans = -1;
    while (L <= R) {
      vector<int> fa(n * n, -1);
      for (int i = 0; i < n * n; ++i) {
        fa[i] = i;
      }
      int mid = L + ((R - L) >> 1);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          for (int k = 0; k < 4; ++k) {
            int tx = i + dir_x[k];
            int ty = j + dir_y[k];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n)
              continue;
            if (grid[i][j] <= mid && grid[tx][ty] <= mid) {
              int idX = i * n + j, idY = tx * n + ty;
              int fX = Find(idX, fa), fY = Find(idY, fa);
              fa[fX] = fY;
            }
          }
        }
      }
      if (Find(0, fa) == Find(n * n - 1, fa)) {
        ans = mid;
        R = mid - 1;
      } else {
        L = mid + 1;
      }
    }
    return ans;
  }
};
