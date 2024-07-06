class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int l = 0, n = nums.size();
        long long ans = 0;
        
        while (l < n) {
            int r = l + 1;
            for (; r < n and nums[r] != nums[r - 1]; ++r);

            ans += 1LL * (r - l) * (r - l + 1) / 2;

            l = r;
        }

        return ans;
    }
};
