class Solution {
public:
    int S[1005][1005];
    int rearrangeSticks(int n, int k) {
		int P = 1000000000 + 7;
        S[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			S[i][0] = 0;
			S[i][i] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int k = 1; k <= i - 1; ++k) {
				S[i][k] = (1LL * (i - 1) * S[i - 1][k] % P + S[i - 1][k - 1]) % P;
			}
		}
		return S[n][k];
    }
};

