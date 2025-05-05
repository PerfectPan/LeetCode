const int MOD = 1'000'000'007;
const int MX = 1001;
long long f[MX];

int init = []() {
    f[0] = f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < MX; ++i) {
        f[i] = (f[i - 1] * 2 + f[i - 3]) % MOD;
    }
    return 0;
}();

class Solution {
public:
    int numTilings(int n) {
        return f[n];
    }
};
