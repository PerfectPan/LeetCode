class TreeAncestor {
public:
    vector<vector<int>> pa;
    TreeAncestor(int n, vector<int>& parent) {
        int m = 32 - __builtin_clz(n);
        pa.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i) {
            pa[i][0] = parent[i];
        }
        for (int i = 0; i < m - 1; ++i) {
            for (int x = 0; x < n; ++x) {
                if (pa[x][i] != -1) {
                    pa[x][i + 1] = pa[pa[x][i]][i];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int m = 32 - __builtin_clz(k);
        for (int i = 0; i < m; ++i) {
            if ((k >> i) & 1) {
                node = pa[node][i];
                if (node < 0) {
                    break;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
