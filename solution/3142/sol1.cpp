class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[j][i] != grid[j - 1][i]) {
                    return false;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            if (grid[0][i] == grid[0][i - 1]) {
                return false;
            }
        }   
        return true;
    }
};
