class Solution {
public:
  bool checkPartitioning(string s) {
    int n = s.length();
    vector<vector<int>> isPa(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      isPa[i][i] = 1;
      if (i + 1 < n) {
        isPa[i][i + 1] = s[i] == s[i + 1];
      }
    }
    for (int len = 3; len < n; ++len) {
      for (int l = 0; l + len - 1 < n; ++l) {
        int r = l + len - 1;
        isPa[l][r] = isPa[l + 1][r - 1] && s[l] == s[r];
      }
    }
    vector<vector<int>> f(n + 1, vector<int>(3, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      f[i][0] = f[i][0] || isPa[0][i - 1];
      for (int j = 0; j < i; ++j) {
        f[i][1] = f[i][1] || (f[j][0] && isPa[j][i - 1]);
        f[i][2] = f[i][2] || (f[j][1] && isPa[j][i - 1]);
      }
    }
    return f[n][2];
  }
};
