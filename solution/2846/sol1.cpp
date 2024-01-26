class Solution {
public:
    vector<pair<int, int>> G[10010];
    int pre[26][10010];
    int lg[10010], fa[20][10010], dep[10010];
    void dfs(int u, int f, int col) {
        for (int i = 0; i < 26; ++i) {
            pre[i][u] = pre[i][f];
        }
        if (col != -1) {
            pre[col - 1][u] += 1;
        }

        fa[0][u] = f;
        dep[u] = dep[f] + 1;

        for (int i = 1; i <= lg[dep[u]]; ++i) {
            fa[i][u] = fa[i - 1][fa[i - 1][u]];
        }

        for (auto &[v, w]: G[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u, w);
        }
    }

    int LCA(int x, int y) {
        if (dep[x] < dep[y]) {
            swap(x, y);
        }
        while (dep[x] > dep[y]) {
            x = fa[lg[dep[x] - dep[y]] - 1][x];
        }
        if (x == y) {
            return x;
        }
        
        for (int k = lg[dep[x]] - 1; k >= 0; --k) {
            if (fa[k][x] != fa[k][y]) {
                x = fa[k][x];
                y = fa[k][y];
            }
        }
        return fa[0][x];
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            u++, v++;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }

        for(int i = 1; i <= n; ++i) {
            lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
        }

        dfs(1, 0, -1);
        vector<int> res;
        for (auto& query: queries) {
            int a = query[0], b = query[1];
            a++, b++;
            int lca = LCA(a, b);
            
            int tmp[26];
            int sum = 0, mx = 0;
            for (int i = 0; i < 26; ++i) {
                tmp[i] = pre[i][a] + pre[i][b] - 2 * pre[i][lca];
                sum += tmp[i];
                mx = max(mx, tmp[i]);
            }

            res.push_back(sum - mx);
        }
        return res;
    }
};
