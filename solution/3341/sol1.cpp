struct Node {
    int x, y, t;

    bool operator < (const Node& rhs) const {
        return this->t > rhs.t;
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<Node> Q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        Q.push(Node{ 0, 0, 0 });
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while (!Q.empty()) {
            auto node = Q.top(); Q.pop();
            if (node.x == n - 1 and node.y == m - 1) {
                return node.t;
            }
            if (vis[node.x][node.y] == 1) {
                continue;
            } else {
                vis[node.x][node.y] = 1;
            }
            for (int i = 0; i < 4; ++i) {
                int tx = node.x + dx[i], ty = node.y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty]) {
                    continue;
                }
                int time = moveTime[tx][ty];
                Q.push(Node{ tx, ty, max(time, node.t) + 1});
            }

        }
        return 0;
    }
};
