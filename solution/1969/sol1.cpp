class Solution {
public:
    int P = 1e9 + 7;
    int fexp(int a, long long n) {
        int res = 1;
        while (n > 0) {
            if (n & 1) {
                res = 1LL * res * a % P;
            }
            n >>= 1;
            a = 1LL * a * a % P;
        }
        return res;
    }
    int minNonZeroProduct(int p) {
        int x = ((1LL << p) - 2) % P;
        int y = ((1LL << p) - 1) % P;
        long long num = (1LL << (p - 1)) - 1;
        return 1LL * fexp(x, num) * y % P;
    }
};
