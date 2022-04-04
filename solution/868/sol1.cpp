class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, lst = -1, cnt = 0;
        while (n) {
            if (n & 1) {
                if (~lst) {
                    ans = max(ans, cnt - lst);
                }
                lst = cnt;
            }
            cnt++;
            n >>= 1;
        }
        return ans;
    }
};

