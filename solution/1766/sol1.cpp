int g[55][55];

auto init = [] {
    for (int i = 1; i <= 50; ++i) {
        for (int j = 1; j <= 50; ++j) {
            if (gcd(i, j) == 1) {
                g[i][j] = g[j][i] = 1;
            } else {
                g[i][j] = g[j][i] = 0;
            }
        }
    }

    return 0;
}();

class Solution {
public:
    vector<vector<int>> G;
    void dfs(int u, int f, int dep, vector<int>& nums, vector<pair<int, int>>& record, vector<int>& ans) {
        int d = 0, id = -1;
        for (int i = 1; i <= 50; ++i) if (record[i].first != -1) {
            if (g[nums[u]][i]) {
                if (record[i].second > d) {
                    d = record[i].second;
                    id = record[i].first;
                }
            }
        }
        ans[u] = id;
        auto prev = record[nums[u]];
        record[nums[u]] = { u, dep };
        for (auto& v: G[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u, dep + 1, nums, record, ans);
        }
        record[nums[u]] = prev;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        G.resize(n);

        for (auto& edge: edges) {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }

        vector<pair<int, int>> f(55, { -1, -1 });
        vector<int> ans(nums.size(), -1);

        dfs(0, -1, 1, nums, f, ans);

        return ans;
    }
};
