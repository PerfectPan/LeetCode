class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> from, to;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    for (int k = 1; k < grid[i][j]; k++) {
                        from.emplace_back(i, j);
                    }
                } else {
                    to.emplace_back(i, j);
                }
            }
        }

        int ans = INT_MAX;
        do {
            int total = 0;
            for (int i = 0; i < from.size(); i++) {
                total += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
            }
            ans = min(ans, total);
        } while (next_permutation(from.begin(), from.end()));
        return ans;
    }
};
