class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int L = 0, R = max(heaters.back(), houses.back()), ans = R;
        while (L <= R) {
            int mid = L + ((R - L) >> 1), i, j;
            for (i = 0, j = 0; i < heaters.size() && j < houses.size();) {
                int l = heaters[i] - mid, r = heaters[i] + mid;
                if (l <= houses[j] && houses[j] <= r) {
                    j++;
                } else {
                    i++;
                }
            }
            if (j == houses.size()) {
                R = mid - 1;
                ans = mid;
            } else {
                L = mid + 1;
            }
        }
        return ans;
    }
};
