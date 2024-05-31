class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int n = grid.size();
        int a, b;
        int total = (1 + n * n) * (n * n) / 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mp.count(grid[i][j])) {
                    a = grid[i][j];
                } else {
                    total -= grid[i][j];
                    mp[grid[i][j]] = 1;
                }
            }
        }
        return { a, total };
    }
};
