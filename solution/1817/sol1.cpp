class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k, 0);
        sort(logs.begin(), logs.end());
        int cnt = 0;
        for (int i = 0; i < logs.size(); ++i) {
            if (i > 0 && logs[i][0] != logs[i - 1][0]) {
                if (cnt - 1 < k) {
                    ans[cnt - 1]++;
                } 
                cnt = 1;
            } else if (i == 0 || logs[i][1] != logs[i - 1][1]) {
                cnt++;
            }
        }
        if (cnt - 1 < k) {
            ans[cnt - 1]++;
        }
        return ans;
    }
};
