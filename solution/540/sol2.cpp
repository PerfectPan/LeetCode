class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() / 2, ans = nums.size() / 2;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (mid * 2 + 1 < nums.size() and nums[mid * 2] != nums[mid * 2 + 1]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return nums[ans * 2];
    }
};
