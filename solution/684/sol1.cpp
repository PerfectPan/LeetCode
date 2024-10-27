class Solution {
public:
    int fa[1005];
    int Find(int x) {return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int ansU, ansV;
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            int fu = Find(u), fv = Find(v);
            if (fu ^ fv) {
                fa[fu] = fv;
            } else {
                ansU = u, ansV = v;
            }
        }
        return vector<int>{ansU, ansV};
    }
};
