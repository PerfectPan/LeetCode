class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        for (int i = 0; i + 3 <= grid.size(); ++i) {
            vector<int> line;
            for (int j = 0; j + 3 <= grid[i].size(); ++j) {
                int res = 0;
                for (int m = i; m < i + 3; ++m) {
                    for (int n = j; n < j + 3; ++n) {
                        res = max(res, grid[m][n]);
                    }
                }
                line.push_back(res);
            }
            ans.push_back(line);
        }
        return ans;
    }
};
