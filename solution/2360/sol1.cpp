class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1;
        vector<int> time(n, 0);
        for (int i = 0, clock = 1; i < n; ++i) {
            if (time[i]) {
                continue;
            }
            for (int u = i, st = clock; ~u; u = edges[u]) {
                if (time[u]) {
                    if (time[u] >= st) {
                        ans = max(ans, clock - time[u]);
                    }
                    break;
                }
                time[u] = clock++;
            }
        }
        return ans;
    }
};

