class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        auto check = [&](int mid) -> bool {
            int p = pills;
            multiset<int> ws;
            for (int i = m - mid; i < m; ++i) {
                ws.insert(workers[i]);
            }

            for (int i = mid - 1; i >= 0; --i) {
                if (auto it = prev(ws.end()); *it >= tasks[i]) {
                    ws.erase(it);
                } else {
                    if (!p) {
                        return false;
                    }
                    auto rep = ws.lower_bound(tasks[i] - strength);
                    if (rep == ws.end()) {
                        return false;
                    }
                    --p;
                    ws.erase(rep);
                }
            }
            return true;
        };

        int l = 1, r = min(m, n), ans = 0;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
