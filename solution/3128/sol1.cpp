class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<int> cnt_row(n, 0);
        vector<int> cnt_col(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt_row[i] += grid[i][j] == 1;
                cnt_col[j] += grid[i][j] == 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) if (grid[i][j] == 1) {
                ans += 1LL * max(0, (cnt_row[i] - 1)) * max(0, (cnt_col[j] - 1));
            }
        }
        return ans;
    }
};


// A * B + B * C + C * D + D * A = A * (B + D) + C * (B + D) = (A + C) * (B + D)
