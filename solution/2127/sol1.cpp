class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> G(n);
        for (int i = 0; i < favorite.size(); ++i) {
            G[favorite[i]].push_back(i);
        }
        vector<int> vis(n, 0);
        vector<int> dis(n, -1);
        int ans = 0, total = 0;
        for (int S = 0; S < n; ++S) if (dis[S] == -1) {
            // 从任意一点出发，都能走到环上，模拟求环长
            int now = S, cnt = 1;
            for (; vis[now] == 0; now = favorite[now], cnt++) {
                vis[now] = cnt;
            }
            int loop = cnt - vis[now];
            int ret = -1, ret2 = -1;
            auto update = [&](int x) -> void {
                if (ret == -1) {
                    ret = x;
                } else if (ret2 == -1) {
                    if (x > ret) {
                        ret2 = ret;
                        ret = x;
                    }  else {
                        ret2 = x;
                    }
                } else if (x > ret) {
                    ret2 = ret;
                    ret = x;
                } else if (x > ret2) {
                    ret2 = x;
                }
            };
            function<int(int)> dfs = [&](int u) -> int {
                int mx = 0;
                for (int v: G[u]) {
                    if (dis[v] == -1) {
                        dis[v] = dis[u] + 1;
                        mx = max(mx, dfs(v) + 1);
                    }
                }
                return mx;
            };
            int cp_now = now;
            dis[now] = 0;
            for (int sn = favorite[now]; sn != now; sn = favorite[sn]) {
                dis[sn] = 0;
            }
            update(dfs(cp_now));
            for (int sn = favorite[now]; sn != cp_now; sn = favorite[sn]) {
                update(dfs(sn));
            }
            if (loop == 2) {
                total += loop + ret + ret2;
                ans = max(ans, total);
            } else {
                ans = max(ans, loop);
            }
        }
        return ans;
    }
};
