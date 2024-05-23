class Solution {
public:
    bool check(int mid, int n, int k, vector<int>& nums) {
        vector<int> mp(n + 1, 0);
        for (int i = 0; i < min(n, mid + k); ++i) {
            mp[nums[i]]++;
            if (mp[nums[i]] == mid) {
                return true;
            }
        }

        for (int i = mid + k; i < n; ++i) {
            mp[nums[i - mid - k]]--;
            mp[nums[i]]++;

            if (mp[nums[i]] == mid) {
                return true;
            }
        }
        return false;
    };
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1, r = n, ans = k;

        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid, n, k, nums)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }     

        return ans;
    }
};
