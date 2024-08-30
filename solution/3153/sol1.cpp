class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        vector<array<int, 10>> cnt(to_string(nums[0]).length());
        for (int num: nums) {
            int t = num;
            int pos = 0;
            while (t > 0) {
                int left = t % 10;
                for (int i = 0; i < 10; ++i) if (i != left) {
                    ans += cnt[pos][i];
                }
                cnt[pos][left]++;
                pos++;
                t /= 10;
            }
        }
        return ans;
    }
};
