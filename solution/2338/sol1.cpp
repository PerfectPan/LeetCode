class Solution {
public:
    int P = 1e9 + 7;
    int C[10020][20];
    void up(int& a, int b) { a += b; if (a >= P) a -= P;}
    int idealArrays(int n, int maxValue) {
        int ans = 0;
        C[0][0] = 1;
        for (int i = 1; i <= n + 13; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= min(i, 13); ++j) {
                up(C[i][j], C[i - 1][j]);
                up(C[i][j], C[i - 1][j - 1]);
            }
        }
        for (int i = 1; i <= maxValue; ++i) {
            int res = 1;
            int t = i;
            for (int j = 2; j * j <= t; ++j) {
                if (t % j == 0) {
                    int cnt = 0;
                    while (t % j == 0) {
                        t /= j;
                        cnt++;
                    }
                    res = 1LL * res * C[n + cnt - 1][cnt] % P;
                }
            }
            if (t > 1) {
                res = 1LL * res * C[n][1] % P;
            }
            up(ans, res);
        }
        return ans;
    }
};

