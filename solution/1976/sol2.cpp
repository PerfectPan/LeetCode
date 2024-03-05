// Dijkstra 求解最短路的时候 DP，假设目前在考虑 u -> v，边长为 d，如果可以更新距离数组，则 dp[u] = dp[v]，如果转移的时候距离相等，则 dp[u] += dp[v]，说明有另一个可行的方案
// 最后返回 dp[n - 1] 即可
using ll = long long;
// 图中不可出现负权路，很多问题可以先用此进行预处理。
struct Edge{
    int from,to,dist;
};
struct HeapNode{
    ll d;
    int u;
    bool operator <(const HeapNode& rhs)const{
        return d>rhs.d;
    }
};
ll INF = 1e18;
constexpr int P = 1e9 + 7;
struct Dijkstra{
    int n,m;
    vector<Edge>edges;
    vector<int>G[300];
    bool done[300];
    ll d[300];
    int dp[300];

    void init(int n){
        this->n=n;
        for (int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int dist){
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s){
        priority_queue<HeapNode>Q;
        for (int i=0;i<n;i++) d[i]=INF,dp[i]=0;
        d[s]=0;
        dp[s]=1;
        memset(done,false,sizeof(done));
        Q.push((HeapNode){0,s});
        while (!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if (done[u]) continue;
            done[u]=true;
            for (int i=0;i<(int)G[u].size();i++){
                Edge &e=edges[G[u][i]];
                if (d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    dp[e.to]=dp[u];
                    Q.push((HeapNode){d[e.to],e.to});
                } else if (d[e.to]==d[u]+e.dist){
                    dp[e.to]=(dp[e.to]+dp[u])%P;
                }
            }
        }
    }
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        Dijkstra solver = Dijkstra();
        solver.init(n);
        for (const auto& road: roads) {
            int u = road[0], v = road[1], t = road[2];
            solver.AddEdge(u, v, t);
            solver.AddEdge(v, u, t);
        }
        solver.dijkstra(0);
        return solver.dp[n - 1];
    }
};
