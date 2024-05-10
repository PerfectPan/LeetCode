class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < batteryPercentages.size(); ++i) {
            if (batteryPercentages[i] - cnt > 0) {
                ans++;
                cnt++;
            }
        }
        return ans;
    }
};
