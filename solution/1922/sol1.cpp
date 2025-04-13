class Solution {
public:
    int P = 1e9 + 7;
    int fexp(int a, long long n) {
        int res = 1;
        while (n) {
            if (n & 1) {
                res = 1LL * res * a % P;
            }
            a = 1LL * a * a % P;
            n >>= 1LL;
        }

        return res;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n - even;

        return 1LL * fexp(5, even) * fexp(4, odd) % P;
    }
};
