class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        int mx = *max_element(stock.begin(), stock.end());
        for (auto& com: composition) {
            int l = 0, r = budget + mx, res = -1;
            while (l <= r) {
                int mid = l + ((r - l) >> 1);

                long long t = 0;
                for (int i = 0; i < com.size(); ++i) {
                    t += max(0LL, 1LL * com[i] * mid - stock[i]) * cost[i];
                }

                if (t <= budget) {
                    res = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            ans = max(ans, res);
        }

        return ans;
    }
};
