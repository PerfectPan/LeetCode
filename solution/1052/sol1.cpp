class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> profit(n + 1, 0);
        int total = 0;
        for (int i = 0; i < n; ++i) {
            profit[i + 1] = grumpy[i] == 1 ? customers[i] : 0;
            total += grumpy[i] == 1 ? 0 : customers[i];
        }
        int p = 0;
        for (int i = 1; i <= min(minutes, n); ++i) {
            p += profit[i];
        }

        int ans = p;
        for (int i = min(minutes, n) + 1; i <= n; ++i) {
            p += profit[i];
            p -= profit[i - minutes];
            ans = max(ans, p);
        }
        return total + ans;
    }
};
