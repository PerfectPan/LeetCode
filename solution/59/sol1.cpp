class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mp(n, vector<int>(n, 0));
        int x = 0, y = 0, dir = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int i = 1; i <= n * n; ++i) {
            mp[x][y] = i;
            int tx = x + dx[dir], ty = y + dy[dir];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n || mp[tx][ty] > 0) {
                dir = (dir + 1) % 4;
                tx = x + dx[dir], ty = y + dy[dir];
            }

            x = tx, y = ty;
        }

        return mp;
    }
};
