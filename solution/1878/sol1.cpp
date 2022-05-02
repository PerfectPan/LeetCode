class Solution {
public:
    int n, m;
    bool ok(int x, int y) {
        return x < 0 || x >= n || y < 0 || y >= m;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        n = grid.size(), m = grid[0].size();
        int sz = min(n, m) / 2;
        for (int i=0;i<n;++i)for(int j=0;j<m;++j)ans.emplace_back(grid[i][j]);
        for (int i = 1; i <= sz; ++i) {
            for (int l = 0; l < n; ++l) {
                for (int r = 0; r < m; ++r) {
                    int sum = 0;
                    int x = l, y = r;
                    bool f = 0;
                    for (int j = 0; j < i; ++j) {
                        x += 1;
                        y += 1;
                        if (ok(x, y)) {
                            f = 1;
                            break;
                        }
                        sum += grid[x][y];
                    }
                    if (f) continue;

                    for (int j = 0; j < i; ++j) {
                        x += 1;
                        y -= 1;
                        if (ok(x, y)) {
                            f = 1;
                            break;
                        }
                        sum += grid[x][y];
                    }  
                    if (f) continue;    

                    for (int j = 0; j < i; ++j) {
                        x -= 1;
                        y -= 1;
                        if (ok(x, y)) {
                            f = 1;
                            break;
                        }
                        sum += grid[x][y];
                    }  
                    if (f) continue;  

                    for (int j = 0; j < i; ++j) {
                        x -= 1;
                        y += 1;
    i = 0; i < 3 && i < ans.size(); ++i) {
            res.emplace_back(ans[i]);
        }
        return res;
    }
};

