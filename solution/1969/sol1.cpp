// 每一位都有 2 ^ (p - 1) 个个数，为了不出现 0， 2 ^ (p - 1) - 1 个数最低位放个 1，其他的数都填满即可
// 根据上面的推论，填满的数应该最低位还剩下 1 个 1，其他位都是满的，因此答案是 (2 ^ p - 2) ^ (2 ^ (p - 1) - 1) * (2 ^ p - 1)
// 2 ^ p - 1 表示那个填满了的数，2 ^ p - 2 表示那个最低位不填其他位填满的数的值
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
