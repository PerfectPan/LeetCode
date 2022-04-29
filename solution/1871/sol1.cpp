class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> f(n + 1, 0), pre(n + 1, 0);
        f[0] = 1;
        for (int i  = 0; i < minJump; ++i) {
            pre[i] = 1;
        }
        for (int i = minJump; i < n; ++i) {
            int l = i - maxJump, r = i - minJump;
            int cnt = pre[r] - (l <= 0 ? 0 : pre[l -1]);
            if (cnt > 0 && s[i] == '0') {
                f[i] = 1;
            }
            pre[i] = pre[i- 1] + f[i];
        }
        return f[n - 1];
    }
};

