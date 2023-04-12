// 枚举边 (u, v)，让它不可走，然后从 u 出发 BFS，看到 v 的最短距离即可
// O(n * m ^ 2), m 为边数
class Solution {
public:
    vector<int> G[1005];
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = -1;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            int dis[n], vis[n];
            for (int j = 0; j < n; ++j) dis[j] = 1e7, vis[j] = 0;
            dis[u] = 0;
            queue<int> Q;
            Q.push(u);
            vis[u] = 1;
            while (!Q.empty()) {
                int t = Q.front(); Q.pop();
                if (t == v) {
                    ans = ans == -1 ? dis[t] + 1 : min(ans, dis[t] + 1);
                    break;
                }
                for (auto nxt: G[t]) {
                    if ((t == u && nxt == v) || (t == v && nxt == u)) {
                        continue;
                    }
                    if (vis[nxt]) {
                        continue;
                    }
                    dis[nxt] = dis[t] + 1;
                    vis[nxt] = 1;
                    Q.push(nxt);
                }
            }
        }
        return ans;
    }
};
