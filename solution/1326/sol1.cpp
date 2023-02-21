class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> seg;
        for (int i = 0; i < ranges.size(); ++i) {
            seg.push_back({ max(0, i - ranges[i]), min(n, i + ranges[i]) });
        }
        sort(seg.begin(), seg.end());

        int r = 0, ans = 0;
        for (int i = 0; i < seg.size() && r < n;) {
            int x = -1;
            while (i < seg.size() && seg[i].first <= r) {
                x = max(x, seg[i].second);
                i++;
            }
            if (x == -1) {
                break;
            }
            ans++;
            r = x;
        }

        return r == n ? ans : -1;
    }
};
