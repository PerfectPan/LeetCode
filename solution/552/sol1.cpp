// f[i][j][k] 前 i 个位置填了连续 j 个 L，已经填了 k 个 A 的方案数
int f[100010][3][2];
int P = 1e9 + 7;

auto init = [] {
    f[1][0][0] = 1;
    f[1][1][0] = 1;
    f[1][0][1] = 1;
    for (int i = 2; i <= 100000; ++i) {
        int v = ((f[i - 1][0][0] + f[i - 1][1][0]) % P + f[i - 1][2][0]) % P;
        f[i][0][0] = v;
        f[i][1][0] = f[i - 1][0][0];
        f[i][2][0] = f[i - 1][1][0];
        int v2 = ((f[i - 1][0][1] + f[i - 1][1][1]) % P + f[i - 1][2][1]) % P;
        f[i][0][1] = (v + v2) % P;
        f[i][1][1] = f[i - 1][0][1];
        f[i][2][1] = f[i - 1][1][1];
    }
    return 0;
}();

class Solution {
public:
    int checkRecord(int n) {
        int ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 2; ++j) {
                ans = (ans + f[n][i][j]) % P;
            }
        }

        return ans;
    }
};
