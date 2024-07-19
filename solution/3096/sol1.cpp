class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += possible[i] == 0 ? -1 : 1;
        }
        int pre = 0;
        for (int i = 0; i < n - 1; ++i) {
            pre += possible[i] == 0 ? -1 : 1;
            if (pre > sum - pre) {
                return i + 1;
            }
        }
        return -1;
    }
};
