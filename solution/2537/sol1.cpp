class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        long long ans = 1LL * n * (n + 1) / 2, curr = 0;;

        for (int l = 0, r = 0; l < n; ++l) {
            while (r < n and curr < k) {
                curr += mp[nums[r]];
                mp[nums[r]]++;
                r++;
            }
            
            int len = r - l - (curr < k ? 0 : 1);
            ans -= len;
            mp[nums[l]]--;
            curr -= mp[nums[l]];
        }

        return ans;      
    }
};
