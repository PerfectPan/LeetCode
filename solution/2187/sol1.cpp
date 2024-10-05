class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, r = 1e14, ans = r;
        while (l <= r) {
            long long mid = l + ((r - l) >> 1LL);
            long long res = 0;
            for (int& t: time) {
                res += mid / t;
            }
            if (res >= totalTrips) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
