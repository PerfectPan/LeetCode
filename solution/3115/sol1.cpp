bool f[101];

auto init = [] {
    for (int i = 2; i <= 100; ++i) {
        bool flag = true;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        f[i] = flag;
    }
    return 0;
}();

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int mn = -1, mx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (f[nums[i]]) {
                if (mn == -1) {
                    mn = mx = i;
                } else {
                    mx = i;
                }
            }
        }
        return mx - mn;
    }
};
