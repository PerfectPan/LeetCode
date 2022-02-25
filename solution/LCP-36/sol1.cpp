class Solution {
public:
    int dp[3][3][100010];
    int cnt[100010];
    int mp[100010];
    int maxGroupNumber(vector<int>& tiles) {
      memset(mp, -1, sizeof(mp));
      vector<int> V;

      for (int i = 0; i < tiles.size(); ++i) {
        V.emplace_back(tiles[i]);
      }

      sort(V.begin(), V.end());
      V.erase(unique(V.begin(), V.end()), V.end());

      int n = V.size();

      for (int i = 0; i < tiles.size(); ++i) {
        int pos = lower_bound(V.begin(), V.end(), tiles[i]) - V.begin() + 1;
        cnt[pos] += 1;
        mp[pos] = tiles[i];
      }
      mp[n+1] = mp[n] + 1;

      for (int i = 1; i <= n; ++i) {
        int x = mp[i], y = mp[i + 1], z = mp[i + 2];
        int A = cnt[i];
        int B = x + 1 == y ? cnt[i + 1] : 0;
        int C = x + 2 == z ? cnt[i + 2] : 0;
        // if (x != -1 && y != -1 && z != -1 && x + 1 == y && y + 1 == z) {
          for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
              for (int c = 0; c < 3; ++c) if (a + b + c <= A && b + c <= B && c <= C) {
                  dp[b][c][i] = max(dp[b][c][i], dp[a][b][i - 1] + (A - a - b - c) / 3 + c);
              }
            }
          }
        // }
        // } else {
        //     dp[0][0][i] = dp[0][0][i - 1] + cnt[i] / 3;    
        //     if (x != -1 && y != -1 && x + 1 == y && (z == -1 || y + 1 != z)) {
        //         for (int a = 0; a < 3; ++a) {
        //             for (int b = 0; b < 3; ++b) if (a + b <= cnt[i] && b <= cnt[i + 1]){
        //                 dp[b][0][i] = max(dp[b][0][i], dp[a][b][i - 1] + (cnt[i] - a - b) / 3);
        //             }
        //         }
        //     }
        // }
      }
    // for (int k = 1; k <= n; ++k)
    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         // for (int k = 1; k <= n; ++k) {
    //             cout<<k<<" "<<i<<" "<<j<<" "<<dp[i][j][k]<<endl;
    //         // }
    //     }
    // }
      return dp[0][0][n];
    }
};

