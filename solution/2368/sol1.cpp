class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> f(n);
        vector<int> G[n];
        for (int u: restricted) {
            f[u] = 1;
        }

        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        function<void(int, int, int&)> dfs = [&](int u, int fa, int& ans) -> void {
            ans++;
            for (int v: G[u]) {
                if (v == fa || f[v]) {
                    continue;
                }
                dfs(v, u, ans);
            }
        };

        int ans = 0;
        dfs(0, -1, ans);
        return ans;
    }
};
