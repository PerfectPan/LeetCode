// 并查集维护连通块，能使答案减少的就是连通块里被感染的节点数有且只有一个
// 统计一下连通块的大小，且当被感染的节点数有且只有一个时更新答案
class Solution {
public:
    vector<int> fa;
    int Find(int x) { return x == fa[x] ? x : Find(fa[x]); }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        sort(initial.begin(), initial.end());
        fa.resize(n);
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) if (graph[i][j]) {
                int fu = Find(i), fv = Find(j);
                if (fu != fv) {
                    fa[fu] = fv;
                }
            }
        }

        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            cnt[Find(i)]++;
        }

        int len = initial.size();
        int ans = -1;
        unordered_map<int, int> id_to_initials;
        for (int u: initial) {
            id_to_initials[Find(u)]++;
        }
        for (int u: initial) if (id_to_initials[Find(u)] == 1) {
            if (ans == -1 || cnt[Find(ans)] < cnt[Find(u)]) {
                ans = u;
            }
        }
        return ans == -1 ? initial[0] : ans;
    }
};
