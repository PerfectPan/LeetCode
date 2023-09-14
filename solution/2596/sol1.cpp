class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> pos;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pos.push_back({i, j});
            }
        }

        sort(pos.begin(), pos.end(), [&](const auto& A, const auto& B) -> bool {
            return grid[A.first][A.second] < grid[B.first][B.second];
        });

        int lx = pos[0].first, ly = pos[0].second;
        for (int i = 1; i < n * m; ++i) {
            int x = pos[i].first, y = pos[i].second;
            if (!((abs(x - lx) == 1 && abs(y - ly) == 2) || (abs(x - lx) == 2 && abs(y - ly) == 1))) {
                return false;
            }
            lx = x, ly = y;
        }

        return true;
    }
};
