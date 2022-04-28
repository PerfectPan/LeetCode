class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int L = 1, R = 1e9, ans = -1;
        int n = dist.size();
        while (L <= R) {
            int mid = (L + R) / 2;
            double res = 0;
            for (int i = 0; i < n; ++i) {
                int d = dist[i];
                if (i == n - 1) {
                    res += 1.0 * d / mid;
                } else {
                    res += (d + mid - 1) /  mid;
                }
            }
            if (res <= hour) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return ans;
    }
};

