class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int L = -1, R = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (L != -1) {
                    ans += 1LL * (1 + R - L + 1) * (R - L + 1) / 2;
                }
                L = R = -1;
            } else {
                if (L == -1) {
                    L = R = i;
                } else {
                    R = i;
                }
            }
        }
        if (L != -1) {
            ans += 1LL * (R - L + 2) * (R - L + 1) / 2;
        }
        return ans;
    }
};

