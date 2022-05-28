class Solution {
public:
    static const int N = 100000 + 10;
    vector<int> G[N];
    vector<int> f, sz;
    int countHighestScoreNodes(vector<int>& parents) {
        int rt = -1;
        int n = parents.size();
        f.resize(n);
        sz.resize(n);
        for (int i = 0; i < parents.size(); ++i) {
            int fa = parents[i];
            if (fa == -1) {
                rt = i;
            } else {
                G[fa].emplace_back(i);
                f[i] = fa;
            }
        }
        long long ans = -1;
        int cnt = 0;
        function<void(int)> dfs = [&] (int u){
            long long res = 1;
            sz[u] = 1;
            for (int i = 0; i < G[u].size(); ++i) {
                int son = G[u][i];
                dfs(son);
                sz[u] += sz[son];
                res = res * 1LL * sz[son];
            }
            res = res * 1LL * max(1, n - sz[u]);
            if (res > ans) {
                ans = res;
                cnt = 1;
            } else if (res == ans) {
                cnt += 1;
            }
        };

        dfs(rt);

        return cnt;
    }   
};

