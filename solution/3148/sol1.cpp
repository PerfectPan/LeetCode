// 问题等价于每个值和其右下方最大值的差值，二维前缀和维护 f[i][j] 表示 (i, j) 到 (n - 1, m - 1) 子矩阵的最大值
// 枚举 (i, j) 即可
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> mx(n + 1, vector<int>(m + 1, INT_MIN));
        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                mx[i][j] = max(grid[i][j], max(mx[i + 1][j], mx[i][j + 1]));
                if (i == n - 1 && j == m - 1) {
                    continue;
                }
                ans = max(ans, max(mx[i + 1][j], mx[i][j + 1]) - grid[i][j]);
            }
        }
        return ans;
    }
};
