class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int unique_size = s.size();
        map<int, int> mp;
        int n = nums.size();
        int l = 0, r = 0, cnt = 0, ans = 0;
        for (; l < n; ++l) {
            while (r < n and cnt < unique_size) {
                if (mp[nums[r]] == 0) {
                    cnt++;
                }
                mp[nums[r]]++;
                r++;
            }
            if (cnt == unique_size) {
                ans += n - r + 1;
            }
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) {
                cnt--;
            }
        }
        return ans;
    }
};
