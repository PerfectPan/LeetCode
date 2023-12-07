class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> G(n);
        for (auto& connection: connections) {
            G[connection[0]].push_back({ connection[1], 1 });
            G[connection[1]].push_back({ connection[0], -1 });
        }
        int ans = 0;
        function<void(int, int)> dfs = [&](int u, int f) -> void {
            for (auto& [v, dir]: G[u]) {
                if (v == f) {
                    continue;
                }
                dfs(v, u);
                if (dir == 1) {
                    ans++;
                }
            }
        };

        dfs(0, -1);
        return ans;
    }
};
