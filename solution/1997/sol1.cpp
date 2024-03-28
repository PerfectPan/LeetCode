class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        const int P = 1'000'000'007;
        int n = nextVisit.size();
        vector<long long> dp(n);
        for (int i = 0; i < n - 1; ++i) {
            int nxt = nextVisit[i];
            dp[i + 1] = (dp[i] * 2 - dp[nxt] + 2 + P) % P;
        }
        return dp[n - 1];
    }
};
