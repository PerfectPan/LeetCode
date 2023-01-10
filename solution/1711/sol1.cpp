class Solution {
public:
    int P = 1000000000 + 7;
    void up(int& a, int b) { a += b; if (a >= P) a -= P;}
    int countPairs(vector<int>& deliciousness) {
        int ans = 0;
        map<int, int> cnt;
        for (auto& x: deliciousness) {
            for (int i = 0; i <= 21; ++i) {
                int y = (1 << i) - x;
                if (cnt.count(y)) {
                    up(ans, cnt[y]);
                }
            }
            cnt[x]++;
        }
        return ans;
    }
};
