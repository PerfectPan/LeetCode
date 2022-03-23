class Solution {
public:
    #define N 105
    vector<int> G[N];
    int col[N];
    bool dfs(int u,int c) {
        col[u] = c;
        for (int i=0; i<(int)G[u].size();++i){
            int v=G[u][i];
            if (!col[v]) {
                if (!dfs(v, 3 - c)) return false;
            }
            else if (col[v] != 3 - c) return false;
        }
        return true;
    } 
    bool isBipartite(vector<vector<int>>& graph) {
        for (int i=0;i<(int)graph.size();++i) {
            for (int j=0;j<(int)graph[i].size();++j){
                G[i].push_back(graph[i][j]);
            }
        }
        bool f = true;
        for (int i=0;i<(int)graph.size();++i)if(!col[i]) {
            f = f && dfs(i, 1);
        }
        return f;
    }
};

