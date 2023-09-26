class Solution {
public:
    int passThePillow(int n, int time) {
        int cnt = (time - 1) / (n - 1);
        int re = (time - 1) % (n - 1);
        return cnt & 1 ? n - 1 - re : 2 + re;
    }
};
