class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0, n = intervals.size();
        vector<vector<int>> ans;
        while (i < n) {
            int l = intervals[i][0], r = intervals[i][1];
            while (i + 1 < n && intervals[i + 1][0] <= r) {
                r = max(r, intervals[i + 1][1]);
                i += 1;
            }
            ans.push_back(vector<int>{l, r});
            i += 1;
        }
        return ans;
    }
};
