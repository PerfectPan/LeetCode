class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n);
        for (auto& edge: edges) {
            G[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(n, -1);
        vector<vector<int>> anc(n);
        int start;

        function<void(int)> dfs = [&](int u) -> void {
            vis[u] = start;
            for (int& v: G[u]) {
                if (vis[v] != start) {
                    anc[v].push_back(start);
                    dfs(v);
                }
            }
        };
        
        for (start = 0; start < n; ++start) {
            dfs(start);
        }
        return anc;
    }
};
