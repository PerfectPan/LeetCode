class Solution {
    const int P = 1000000007;
    using ll = long long;
public:
    void up(int& a, int b) { a += b; if (a >= P) a -= P; }
    int idealArrays(int n, int maxValue) {
        vector<int> prime(maxValue + 1, 0);
        vector<int> f(maxValue + 1, 0);
        vector<int> cnt(maxValue + 1, 0);
        vector<int> I(20, 0);
        bool vis[maxValue + 1];
        memset(vis, 0, sizeof(vis));
        int ans = maxValue;
        I[1] = 1;
        for (int i = 2; i < 20; ++i) {
            I[i] = 1LL * (P - P / i) * I[P % i] % P;
        }
        f[1] = 1;
        for (int i = 2; i <= maxValue; ++i) {
            if (!vis[i]) {
                f[prime[++prime[0]] = i] = n - 1;
                cnt[i] = 1;
            }
            up(ans, 1LL * maxValue / i * f[i] % P);
            for (int j = 1; j <= prime[0] && i * prime[j] <= maxValue; ++j) {
                vis[i * prime[j]] = 1;
                if (i % prime[j] == 0) {
                    f[i * prime[j]] = 1LL * f[i] * (cnt[i] + n - 1) % P * I[cnt[i] + 1] % P;
                    cnt[i * prime[j]] = cnt[i] + 1;
                    break;
                } else {
                    f[i * prime[j]] = 1LL * f[i] * (n - 1) % P;
                    cnt[i * prime[j]] = 1;
                }
            }
        }
        return ans;
    }
};
