class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        int n = costs.size();
        int l = 0;
        for (; l < candidates && l < n; ++l) {
            Q.push({ costs[l], l });
        }
        int r = n - 1;
        for (; r >= l && n - r <= candidates; --r) {
            Q.push({ costs[r], r });
        }

        long long ans = 0;
        for (; k > 0; --k) {
            auto [v, idx] = Q.top(); Q.pop();
            ans += v;
            if (idx <= l) {
                if (l <= r) {
                    Q.push({ costs[l], l });
                }
                l++;
            } else {
                if (l <= r) {
                    Q.push({ costs[r], r });
                }
                r--;
            }
        }
        return ans;
    }
};
