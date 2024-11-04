class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; 1LL * i * i <= c; i += 1) {
            int b = sqrt(c - i * i);
            if (i * i + b * b == c) {
                return true;
            }
        }
        return false;
    }
};
