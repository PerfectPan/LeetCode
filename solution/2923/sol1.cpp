class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        for (int i = 1; i < n; ++i) {
            if (grid[i][ans]) {
                ans = i;
            }
        }

        return ans;
    }
};
