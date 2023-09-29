class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int r = -1, ans = 0;
        for (int time: timeSeries) {
            ans += time + duration - max(r, time);
            r = time + duration;
        }
        return ans;
    }
};
