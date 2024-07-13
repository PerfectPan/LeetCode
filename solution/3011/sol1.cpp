class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, lst_mx = -1;
        while (l < n) {
            int r = l;
            int bit = __builtin_popcount(nums[l]);
            int mx = nums[l], mn = nums[l];
            for (; r < n && __builtin_popcount(nums[r]) == bit; mx = max(mx, nums[r]), mn = min(mn, nums[r]), ++r);

            if (lst_mx > mn) {
                return false;
            }

            lst_mx = mx;
            l = r;
        }

        return true;
    }
};
