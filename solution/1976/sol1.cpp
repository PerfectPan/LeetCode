struct Edge{
    int from,to,dist;
};
struct HeapNode{
    long long d;
    int u;
    bool operator <(const HeapNode& rhs)const{
        return d>rhs.d;
    }
};
struct Dijkstra{
    int n,m;
    #define maxn 210
    #define INF 1e15
    #define P 1000000007
    vector<Edge>edges;
    vector<int>G[maxn];
    vector<int>G2[maxn];
    bool done[maxn];
    long long d[maxn];
    int dp[maxn];
    int p[maxn];

    void init(int n){
        this->n=n;
        for (int i=0;i<n;i++) G[i].clear(), G2[i].clear();
        edges.clear();
        memset(dp, -1, sizeof(dp));
    }

    void AddEdge(int from,int to,int dist){
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s){
        priority_queue<HeapNode>Q;
        for (int i=0;i<n;i++) d[i]=INF;
        d[s]=0;
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
                    p[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }

    int dfs(int u) {
        if (~dp[u]) {
            return dp[u];
        }

        int x = 0;
        for (auto& v: G2[u]) {
            x = (x + dfs(v)) % P;
        }

        return dp[u] = G2[u].size() > 0 ? x : 1;
    }

    int count(int st, int ed) {
        int ans = 0;
        for (auto edge: edges) {
            int u = edge.from, v = edge.to, t = edge.dist;
            if (d[u] + t == d[v]) {
                G2[v].emplace_back(u);
            }
        }
        dfs(ed);
        return dp[ed];
    }
};
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        Dijkstra solver;
        solver.init(n);
        for (auto& road: roads) {
            int u = road[0], v = road[1], time = road[2];
            solver.AddEdge(u, v, time);
            solver.AddEdge(v, u, time);
        }
        solver.dijkstra(0);
        return solver.count(0, n - 1);
    }
};
