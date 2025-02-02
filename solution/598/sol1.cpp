class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mx = m, mn = n;
        for (auto& op: ops) {
            mx = min(mx, op[0]);
            mn = min(mn, op[1]);
        }
        return mx * mn;
    }
};
