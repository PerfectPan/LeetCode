class Solution {
public:
    int P = 1e9 + 7;
    int dp[23][200];
    int dfs(const string& s, int pos, int sum, bool limit, int x, int y) {
        if (pos == -1) {
            return sum >= x && sum <= y;
        }
        if (!limit && ~dp[pos][sum]) {
            return dp[pos][sum];
        }
        int ret = 0;
        int up = limit ? s[pos] - '0' : 9;
        for (int i = 0; i <= up; ++i) {
            if (sum + i <= y) {
                ret = (ret + dfs(s, pos - 1, sum + i, limit && i == up, x, y)) % P;
            }
        }
        if (!limit) {
            dp[pos][sum] = ret;
        }
        return ret;
    }
    int f(string& s, int x, int y) {
        reverse(s.begin(), s.end());
        return dfs(s, (int)s.length() - 1, 0, true, x, y);
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        auto isValid = [&](const string& s) -> bool {
            int sum = 0;
            for (auto& ch: s) {
                sum += ch - '0';
            }
            return sum >= min_sum && sum <= max_sum;
        };
        int ans = f(num2, min_sum, max_sum) - f(num1, min_sum, max_sum) + isValid(num1);
        return (ans % P + P) % P;
    }
};
