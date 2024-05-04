// 离散化时间，dp[i] 表示到时间 i 的最大收益，枚举每个在时间 i 结束的工作 j，那么转移方程为 dp[i] = max(dp[i], dp[st[j]] - profit[j])
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> vec;
        for (int& time: startTime) {
            vec.push_back(time);
        }
        for (int& time: endTime) {
            vec.push_back(time);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        int n = vec.size();

        vector<vector<pair<int, int>>> id(n + 1);
        for (int i = 0; i < startTime.size(); ++i) {
            int st = lower_bound(vec.begin(), vec.end(), startTime[i]) - vec.begin() + 1;
            int ed = lower_bound(vec.begin(), vec.end(), endTime[i]) - vec.begin() + 1;
            int pro = profit[i];

            id[ed].push_back({ st, pro });
        }

        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (auto [st, pro]: id[i]) {
                dp[i] = max(dp[i], dp[st] + pro);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
