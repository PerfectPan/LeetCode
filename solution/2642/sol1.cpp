class Graph {
private:
    const int INF = INT_MAX / 3;
    vector<vector<int>> dist;
public:
    Graph(int n, vector<vector<int>>& edges) {
        dist.resize(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            dist[u][v] = cost;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (dist[i][k] == INF) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (w >= dist[u][v]) {
            return;
        }

        int n = dist.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][u] + w + dist[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return dist[node1][node2] < INF ? dist[node1][node2] : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
