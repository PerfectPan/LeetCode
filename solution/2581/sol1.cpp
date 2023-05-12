// 统计每个节点为根结点猜中的答案，如果答案 >=k 就加一，先 DFS 一遍，再换根统计即可，两遍遍历
class Solution {
public:
    vector<int> G[100000 + 10];
    set<pair<int, int>> S;
    int ans = 0;
    void dfs(int u, int f, int& ans) {
        if (f != -1) {
            if (S.find({f, u}) != S.end()) {
                ans++;
            }
        }
        for (auto& v: G[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u, ans);
        }
    }
    void count(int u, int f, int& ans, int& k, int& res) {
        if (ans >= k) {
            res++;
        }
        
        for (auto& v: G[u]) {
            if (v == f) {
                continue;
            }
            int pre = ans;
            if (S.find({u, v}) != S.end()) {
                ans--;
            }
            if (S.find({v, u}) != S.end()) {
                ans++;
            }
            count(v, u, ans, k, res);
            ans = pre;
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        for (auto edge: edges) {
            int u = edge[0], v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        for (auto guess: guesses) {
            int a = guess[0], b = guess[1];
            S.insert({a, b});
        }
        int ans = 0;
        dfs(0, -1, ans);
        int res = 0;
        count(0, -1, ans, k, res);
        return res;
    }
};
