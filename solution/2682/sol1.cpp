class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> vis(n + 1, 0);
        int lst = 0, cnt = 1;
        while (!vis[lst]) {
            vis[lst] = 1;
            lst = (lst + 1LL * cnt * k % n) % n;
            cnt++;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
