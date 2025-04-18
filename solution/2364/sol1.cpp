class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1LL * n * (n - 1) / 2;
        // j - i = nums[j] - nums[i]
        // j - nums[j] = i - nums[i]
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int cnt = mp[i - nums[i]];
            ans -= cnt;
            mp[i - nums[i]]++;
        }
        return ans;
    }
};
