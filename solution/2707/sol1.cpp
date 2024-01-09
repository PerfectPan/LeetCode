// dp[i] 表示到 i 为结尾最优分割方案，枚举 [0..i] 转移即可
// 时间复杂度 O(n^3)
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;
        unordered_set<string> S(dictionary.begin(), dictionary.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (S.count(s.substr(j, i - j + 1))) {
                    dp[i + 1] = min(dp[i + 1], dp[j]);
                } else {
                    dp[i + 1] = min(dp[i + 1], dp[j] + i - j + 1);
                }
            }
        }
        return dp[n];
    }
};
