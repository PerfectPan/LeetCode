// 跑最短路的时候额外判断一下最小距离是否小于消失的时间即可
// 图中不可出现负权路，很多问题可以先用此进行预处理。
const int maxn = 5e4 + 10;
const int INF = 1e9;
struct Edge{
    int from,to,dist;
};
struct HeapNode{
    int d,u;
    bool operator <(const HeapNode& rhs)const{
        return d>rhs.d;
    }
};
struct Dijkstra{
    int n,m;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool done[maxn];
    int d[maxn];
    int p[maxn];
    int disappear[maxn];

    void init(int n, vector<int>& t){
        this->n=n;
        for (int i=0;i<n;i++) {
            G[i].clear();
            disappear[i] = t[i];
        }
        edges.clear();
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
                if (d[e.to]>d[u]+e.dist && d[u]+e.dist < disappear[e.to]){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
}solver;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        solver.init(n, disappear);
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            solver.AddEdge(u, v, w);
            solver.AddEdge(v, u, w);
        }
        solver.dijkstra(0);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = solver.d[i] == INF ? -1 : solver.d[i];
        }
        return ans;
    }
};
