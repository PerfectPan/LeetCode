// 暴力，查询用树状数组加速，分跟点 u 连和不跟 u 连，分开统计
class Solution {
public:
    #define MP make_pair
    int total, c[200010];
    int lowbit(int x) {return x & (-x);}
    int query(int n) {
        int ans = 0;
        for (int pos = n; pos; pos -= lowbit(pos)) {
            ans += c[pos];
        }
        return ans;
    }
    void add(int x, int k) {
        while (x <= total) {
            c[x] = c[x] + k;
            x = x + lowbit(x);
        }
    }
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> du(n + 1, 0);
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][0] > edges[i][1]) {
                swap(edges[i][0], edges[i][1]);
            }
        }
        sort(edges.begin(), edges.end());
        vector<vector<pair<int, int>>> G(n + 1);
        for (int i = 0, cnt = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            du[u]++;
            du[v]++;
            if (i > 0 && edges[i - 1][0] == u && edges[i - 1][1] == v) {
                G[u].back().second++;
            } else {
                G[u].push_back(MP(v, 1));
            }
        }
        total = (int)edges.size() * 2 + 1;
        for (int i = 1; i <= n; ++i) {
            add(du[i] + 1, 1);
        }
        vector<int> res;
        for (auto q: queries) {
            int ans = 0;
            for (int u = 1; u <= n; ++u) {
                for (auto& [v, cnt]: G[u]) {
                    if (du[u] + du[v] - cnt > q) {
                        ans++;
                    }
                    add(du[v] + 1, -1);
                }
                add(du[u] + 1, -1);
                ans += query(total) - query(max(0, q - du[u] + 1));
                for (int i = 0; i < G[u].size(); ++i) {
                    int v = G[u][i].first;
                    add(du[v] + 1, 1);
                }
            }
            for (int u = 1; u <= n; ++u) {
                add(du[u] + 1, 1);
            }
            res.push_back(ans);
        }
        return res;
    }
};
