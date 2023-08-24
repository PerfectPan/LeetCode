// 用 row[i] 和 col[j] 记录第 i 行和第 j 列的服务器数量
// 第二次遍历的时候只要 row[i] 或者 col[j] > 1 这个点的服务器就满足条件
// 时间复杂度 O(nm)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                row[i] += grid[i][j] == 1;
                col[j] += grid[i][j] == 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] and (row[i] > 1 or col[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
