// 二分答案 x，check 的时候尽可能的让一段的数字和小于等于 x，算划分完以后的段数 cnt
// 如果 cnt <= k 说明满足答案，更新边界即可
// 时间复杂度 O(n * log U), U 表示二分的上界
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 1e9, ans = 1e9;
        for (int i = 0; i < n; ++i) {
            l = max(l, nums[i]);
        }
        auto check = [&](int x) -> bool {
            int i = 0, cnt = 0;
            while (i < n) {
                int r = i, sum = 0;
                for ( ; r < n && sum + nums[r] <= x; r++) {
                    sum += nums[r];
                }
                cnt++;
                i = r;
            }
            return cnt <= k;
        };

        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
