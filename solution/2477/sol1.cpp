// 考虑每一条树边对答案的贡献，为经过这条边的节点数量 / seats 上取整
// DFS 遍历整棵树即可计算出来，时间复杂度 O(n)
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> G[n + 1];
        for (int i = 0; i < n; ++i) {
            int u = roads[i][0], v = roads[i][1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        long long ans = 0;
        function<int(int, int)> dfs = [&](int u, int f) -> int {
            int sum = 1;
            for (int& v: G[u]) {
                if (v == f) {
                    continue;
                }
                int sz = dfs(v, u);
                ans += (sz + seats - 1) / seats;
                sum += sz;
            }
            return sum;
        };

        dfs(0, -1);
        return ans;
    }
};
