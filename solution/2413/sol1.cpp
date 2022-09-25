int gcd(int a, int b) { return b ? gcd(b, a % b) : a;}
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n / gcd(n, 2) * 2;
    }
};
