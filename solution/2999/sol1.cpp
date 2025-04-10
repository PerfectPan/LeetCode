class Solution {
public:
    using ll = long long;
    int digit[20];
    ll f[20][10];
    ll dfs(int pos, int last, bool limit, int mx, string& s) {
        if (pos < 0) {
            return 1;
        }
        if (!limit and ~f[pos][last]) {
            return f[pos][last];
        }
        int up = limit ? digit[pos] : mx;
        ll res = 0;
        int len = s.length();
        for (int i = 0; i <= min(mx, up); ++i) {
            if (pos < len) {
                if (i == s[len - pos - 1] - '0') {
                    res += dfs(pos - 1, i, limit and i == up, mx, s);
                }
            } else {
                res += dfs(pos - 1, i, limit and i == up, mx, s);
            }
        }

        if (!limit) {
            f[pos][last] = res;
        }
        return res;
    }
    ll get(ll n, int limit, string& s) {
        int cnt = 0;
        while (n > 0) {
            digit[cnt++] = n % 10;
            n /= 10;
        }
        if (cnt < s.length()) {
            return 0LL;
        }
        return dfs(cnt - 1, 0, true, limit, s);
    }
    ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
        memset(f, -1, sizeof(f));
        return get(finish, limit, s) - get(start - 1, limit, s);
    }
};
