// 模拟题意，尽量让一次登舱满载
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if (boardingCost * 4 - runningCost < 0) {
            return -1;
        }
        int ans = 0, res = 0, idx = -1;
        int left = 0, i;
        for (i = 0; i < customers.size(); ++i) {
            res -= runningCost;
            left += customers[i];
            res += min(4, left) * boardingCost;
            left -= min(4, left);
            if (res > ans) {
                ans = res;
                idx = i + 1;
            }
        }
        int cnt = left / 4;
        res += cnt * 4 * boardingCost - cnt * runningCost;
        i += cnt;
        if (res > ans) {
            ans = res;
            idx = i;
        }
        res += left % 4 * boardingCost - runningCost;
        i += 1;
        if (res > ans) {
            ans = res;
            idx = i; 
        }
        return idx;
    }
};
