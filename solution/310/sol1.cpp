class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n);
        vector<int> fa(n, 0);
        for (auto& edge: edges) {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        int mx_rt = 0, mx_dep = 0;
        function<void(int, int, int)> dfs = [&](int u, int f, int dep) -> void {
            if (dep > mx_dep) {
                mx_rt = u;
                mx_dep = dep;
            }
            fa[u] = f;
            for (int v: G[u]) {
                if (v == f) {
                    continue;
                }
                dfs(v, u, dep + 1);
            }
        };
        dfs(0, -1, 0);

        mx_dep = 0;

        int rt = mx_rt;
        dfs(rt, -1, 0);
        vector<int> path;
        while (~mx_rt) {
            path.push_back(mx_rt);
            mx_rt = fa[mx_rt];
        }
        int sz = path.size();
        if (sz % 2 == 0) {
            return { path[sz / 2 - 1], path[sz / 2] };
        }
        return { path[sz / 2] };
    }
};
