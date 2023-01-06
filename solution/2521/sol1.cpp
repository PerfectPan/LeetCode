class Solution {
public:
    int cnt[1005];
    int distinctPrimeFactors(vector<int>& nums) {
        memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            for (int j = 2; j < x; ++j) {
                if (x % j == 0) {
                    cnt[j]++;
                    while (x % j == 0) {
                        x /= j;
                    }
                }
            }
            if (x > 1) {
                cnt[x]++;
            }
        }
        for (int i = 2; i <= 1000; ++i) {
            ans += cnt[i] > 0;
        }
        return ans;
    }
};
