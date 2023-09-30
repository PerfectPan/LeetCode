// dp[0][u] 表示以 u 为起点，以 u 的子树中某个节点为终点的路径中，所有点编号都是合数的路径有几条
// dp[1][u] 表示以 u 为起点，以 u 的子树中某个节点为终点的路径中，有一个点编号是质数的路径有几条
// for v in son(u):
//     # 路径上深度最低的节点为 u，这样的合法路径有几条
//     answer += dp[0][u] * dp[1][v] + dp[0][v] * dp[1][u]
//     # 更新以 u 为起点，且走到子树里的路径数量
//     if u is prime:
//         dp[1][u] += dp[0][v]
//     else:
//         dp[0][u] += dp[0][v]
//         dp[1][u] += dp[1][v]
// 时间复杂度 O(n)
using ll = long long;
const int N = 1e5 + 10;
bool inited = false, vis[N];
int primes[N];
void init() {
    if (inited) {
        return;
    }
    inited = true;
    for (int i = 1; i < N; ++i) {
        vis[i] = 0;
    }
    vis[1] = 1;
    primes[0] = 0;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            primes[++primes[0]] = i;
        }
        for (int j = 1; j <= primes[0] && 1LL * primes[j] * i < N; ++j) {
            vis[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                break;
            }   
        }
    }
}
class Solution {
public:
    vector<vector<int>> G;
    vector<ll> dp[2];
    ll INF = 1e15;
    void dfs(int u, int f, ll& ans) {
        dp[0][u] = vis[u];
        dp[1][u] = !vis[u];

        for (int v: G[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u, ans);
            ans += 1LL * dp[0][u] * dp[1][v];
            ans += 1LL * dp[1][u] * dp[0][v];
            dp[0][u] += vis[u] ? dp[0][v] : 0;
            dp[1][u] += vis[u] ? dp[1][v] : dp[0][v];
        }
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        G.resize(n + 1);
        init();
        for (int i = 0; i < 2; ++i) {
            dp[i].resize(n + 1, 0);
        }
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ll ans = 0; 
        dfs(1, 0, ans);
        return ans;
    }
};
