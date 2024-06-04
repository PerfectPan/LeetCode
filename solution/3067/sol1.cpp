class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> G(n);
        for (auto& e: edges) {
            int u = e[0], v = e[1], w = e[2];
            G[u].push_back({ v, w });
            G[v].push_back({ u, w });
        }

        function<int(int, int, int)> dfs = [&](int u, int f, int s) -> int {
            int c = s % signalSpeed == 0;
            for (auto& [v, w]: G[u]) {
                if (v == f) {
                    continue;
                }
                c += dfs(v, u, s + w);
            }
            return c;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (auto& [v, w]: G[i]) {
                int cnt = dfs(v, i, w);
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }

        return ans;
    }
};
