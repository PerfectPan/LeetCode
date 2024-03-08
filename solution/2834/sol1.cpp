class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        long long P = 1e9 + 7;
        int num = min(n, target / 2);
        return ((1LL * (1 + num) * num / 2) % P + (1LL * (1LL * target + target + n - num - 1) * (n - num) / 2) % P) % P;
    }
};
