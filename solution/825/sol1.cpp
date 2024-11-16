class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int l = 0, ans = 0, cnt = 0;
        sort(ages.begin(), ages.end());
        for (int r = 0; r < ages.size(); ++r) {
            if (ages[r] < 15) {
                continue;
            }
            while (l < r) {
                if (ages[r] / 2 + 7 >= ages[l]) {
                    l++;
                } else {
                    break;
                }
            }
            if (r > 0 and ages[r] == ages[r - 1]) {
                cnt++;
            } else {
                cnt = 0;
            }
            ans += r - l + cnt;
        }
        return ans;
    }
};
