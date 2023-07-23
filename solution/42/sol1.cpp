// 相向双指针，本质上每个位置的雨水量 = min(左边最大，右边最大)，然后我们设置两个端点往中间走
// 且维护到这个端点为止的最大值，如果 lmx < rmx，说明这个点的贡献肯定是 lmx 了，因为 rmx 只会不断增大
// 所以移动左指针，lmx >= rmx 同理
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1, ans = 0, lmx = 0, rmx = 0;
        while (l < r) {
            lmx = max(lmx, height[l]);
            rmx = max(rmx, height[r]);
            if (lmx < rmx) {
                ans += lmx - height[l];
                l++;
            } else {
                ans += rmx - height[r];
                r--;
            }
        }
        
        return ans;
    }
};
