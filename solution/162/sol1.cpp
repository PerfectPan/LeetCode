// 如果 nums[mid] > nums[mid + 1]，说明 [l, mid] 一定存在峰值，[mid + 1, r] 可能存在峰值
// 所以把搜索范围收窄到 [l, mid]，不断迭代即可
// 时间复杂度 O(log n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, ans = 0;
        nums.push_back(INT_MIN);
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] > nums[mid + 1]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
