class Solution {
public:
    int dp[1005], a[1005];
    int P = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        dp[1] = 1;
        a[1] = 1;
        for (int i = 2; i <= n; ++i) {
          dp[i] = dp[i - 1];
          if (i - forget >= 1) {
            dp[i] -= a[i - forget];
            dp[i] %= P;
            if (dp[i] < 0) dp[i] += P;
          }
          int sum = 0;
          for (int j = i - forget + 1; j <= i - delay; ++j) {
            if (j >= 1) {
              sum = (sum + a[j]) % P;
            }
          }
          a[i] = sum;
          dp[i] = (dp[i] + sum) % P;
        }
        return dp[n];
    }
};

