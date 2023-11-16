// 分组循环即可
// 时间复杂度 O(n)
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int i = 0, n = nums.size();
        int ans = 0;
        while (i < n) {
            if (nums[i] > threshold || nums[i] % 2 != 0) {
                i++;
                continue;
            }
            int r = i;
            for (int odd = 0; r < n && nums[r] % 2 == odd && nums[r] <= threshold; ++r, odd ^= 1);
            ans = max(ans, r - i);
            i = r;
        }   
        return ans;
    }
};
