class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            int x = i, y = 0;
            vector<int> t;
            while (x < n and y < m) {
                t.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(t.begin(), t.end());
            x = i, y = 0;
            int idx = 0;
            while (x < n and y < m) {
                res[x][y] = t[idx];
                idx++;
                x++;
                y++;
            }
        }
        for (int i = 1; i < m; ++i) {
            int x = 0, y = i;
            vector<int> t;
            while (x < n and y < m) {
                t.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(t.begin(), t.end());
            x = 0, y = i;
            int idx = 0;
            while (x < n and y < m) {
                res[x][y] = t[idx];
                idx++;
                x++;
                y++;
            }
        }

        return res;
    }
};
