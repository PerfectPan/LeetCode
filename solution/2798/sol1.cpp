class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt = 0;
        for (int& hour: hours) {
            cnt += hour >= target;
        }
        return cnt;
    }
};
