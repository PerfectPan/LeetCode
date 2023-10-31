// 启发式合并，每次优先递归最重（节点数量最多）的孩子
// 时间复杂度 O(nlogn)
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> G[n];
        vector<int> sz(n, 0);
        vector<int> son(n, -1);
        vector<int> ans(n, 0);
        unordered_set<int> mex[n];
        for (int i = 0; i < parents.size(); ++i) {
            if (~parents[i]) {
                G[parents[i]].push_back(i);
            }
        }

        function<void(int)> dfs = [&](int u) -> void {
            sz[u] = 1;
            int mx = -1, idx = -1;
            for (int v: G[u]) {
                dfs(v);
                if (sz[v] > mx) {
                    mx = sz[v];
                    idx = v;
                }
                sz[u] += sz[v];
            }
            son[u] = idx;
        };

        function<void(int)> getAns = [&](int u) -> void {
            if (son[u] == -1) {
                mex[u].insert(nums[u]);
                ans[u] = nums[u] == 1 ? 2 : 1;
                return;
            }
            getAns(son[u]);
            mex[u] = move(mex[son[u]]);
            ans[u] = ans[son[u]];
            for (int v: G[u]) {
                if (v == son[u]) {
                    continue;
                }
                getAns(v);
                for (auto x: mex[v]) {
                    mex[u].insert(x);
                }
            }
            mex[u].insert(nums[u]);
            while (mex[u].count(ans[u])) {
                ans[u]++;
            }
        };

        dfs(0);
        getAns(0);
        return ans;
    }
};
