class Solution {
public:
    int cnt[32];
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (auto& num: nums) {
            int bit = __builtin_popcount(num);
            cnt[bit]++;
            for (int i = max(0, k - bit); i <= 30; ++i) {
                ans += cnt[i] * 2;
            }
            if (bit >= max(0, k - bit)) {
                ans -= 1;
            }
        }
        return ans;
    }
};

