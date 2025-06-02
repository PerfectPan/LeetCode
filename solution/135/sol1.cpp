class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int, int>> kids(n);
        for (int i = 0; i < ratings.size(); ++i) {
            kids[i] = { ratings[i], i };
        }
        sort(kids.begin(), kids.end());
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int cur_idx = kids[i].second;

            int before = cur_idx > 0 ? res[cur_idx - 1] : -1;
            int after = cur_idx < n - 1 ? res[cur_idx + 1] : -1;
            if (cur_idx > 0 && ratings[cur_idx - 1] == ratings[cur_idx]) {
                before = -1;
            }
            if (cur_idx < n - 1 && ratings[cur_idx + 1] == ratings[cur_idx]) {
                after = -1;
            }
            int mx = max(before, after);
            res[cur_idx] = max(0, mx) + 1;
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};
