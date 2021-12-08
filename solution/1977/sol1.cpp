class Solution {
public:
    #define P 1000000007
    using ull = unsigned long long;
    ull base = 233;
    vector<ull> f;
    vector<ull> Po;
    inline void up(int& a,int b) { a += b; if (a >= P) a -= P; }
    bool cmp(string& s, int a, int b, int c, int d) {
        if (getHash(a + 1, b + 1) == getHash(c + 1, d + 1)) {
            return true;
        }
        for (int i = a, j = c; i <= b; ++i, ++j) {
            if (s[i] != s[j]) {
                return s[i] > s[j];
            }
        }
        return true;
    }
    ull getHash(int l,int r) { return f[r] - f[l-1] * Po[r - l + 1]; }
    int numberOfCombinations(string num) {
        int len = num.size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        vector<vector<int>> CMP(len + 1, vector<int>(len + 1, 0));
        f.resize(len + 1, 0);
        Po.resize(len + 1, 0);
        for (int i = 1; i <= len; ++i) {
            f[i] = f[i - 1] * base + num[i - 1];
        }
        Po[0] = 1;
        for (int i = 1; i <= len; ++i) {
            Po[i] = Po[i - 1] * base;
        }
        for (int l = 1; l <= len / 2; ++l) {
            for (int i = 1; i + l + l - 1 <= len; ++i) {
                int LL = i + l, RR = i + l + l - 1;
                int L = i, R = i + l - 1;

                CMP[LL - 1][RR - 1] = cmp(num, LL - 1, RR - 1, L - 1, R - 1);
            }
        }
        dp[0][0] = 1;
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j < i; ++j) {
                if (num[i - j] != '0') {
                    if (i - j < j) {
                        dp[i][j] = dp[i - j][i - j];
                    } else {
                        dp[i][j] = dp[i - j][j - 1];
                        if (i - 2 * j >= 0 && num[i - 2 * j] != '0' && CMP[i - j][i - 1]) {
                            dp[i][j] = dp[i - j][j];
                        }
                    }
                    
                }
            }
            
            dp[i][i] = num[0] != '0';

            for (int j = 1; j <= i; ++j) {
                up(dp[i][j], dp[i][j - 1]); 
            }
        }

        return dp[len][len];
    }
};
