class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        map<int, long long> mp;
        long long day = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            if (!mp[tasks[i]]) {
                day++;
            } else {
                day = max(day + 1, mp[tasks[i]] + space + 1);
            }
            mp[tasks[i]] = day;
        }
        return day;
    }
};
