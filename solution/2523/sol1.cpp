class Solution {
public:
    int pri[1000010];
    int vis[1000010];
    void init(int n) {
        for (int i = 2; i <= n; ++i) {
            if (!vis[i]) {
                pri[++pri[0]] = i;
            }
            for (int j = 1; j <= pri[0]; ++j) {
                if (1ll * i * pri[j] > n) break;
                vis[i * pri[j]] = 1;
                if (i % pri[j] == 0) {
                    break;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        init(right);
        int l = -1;
        for (int i = 1; i <= pri[0]; ++i) {
            if (pri[i] >= left && pri[i] <= right) {
                l = i;
                break;
            }
        }
        if (l == -1) {
            return {-1, -1};
        }
        int ans = -1, idx = -1;
        for (int i = l + 1; i <= pri[0]; ++i) {
            if (pri[i] > right) {
                break;
            }
            int gap = pri[i] - pri[i - 1];
            if (ans == -1) {
                ans = gap;
                idx = i - 1;
            } else {
                if (ans > gap) {
                    ans = gap;
                    idx = i - 1;
                }
            }
        }
        if (idx == -1) {
            return {-1, -1};
        }
        return {pri[idx], pri[idx + 1]};
    }
};
