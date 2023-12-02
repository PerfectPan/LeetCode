class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pre(1010, 0);
        for (auto& trip: trips) {
            int num = trip[0], from = trip[1], to = trip[2];
            pre[from] += num;
            pre[to] -= num;
        }
        int mx = pre[0];
        for (int i = 1; i <= 1000; ++i) {
            pre[i] += pre[i - 1];
            mx = max(mx, pre[i]);
        }
        return mx <= capacity;
    }
};
