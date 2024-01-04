class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int n = matrix.size(), m = matrix[0].size();
        int S = 1 << m;
        int ans = 0;
        vector<int> mask(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mask[i] += matrix[i][j] << j;
            }
        }
        for (int i = 0; i < S; ++i) {
            int bit_count = __builtin_popcount(i);
            if (bit_count != numSelect) {
                continue;
            }
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if ((mask[j] & i) == mask[j]) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
