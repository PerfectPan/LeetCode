class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int min_i = -1, max_i = -1, i0 = -1;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (x == minK) {
                min_i = i; // 最近的 minK 位置
            }
            if (x == maxK) {
                max_i = i; // 最近的 maxK 位置
            }
            if (x < minK || x > maxK) {
                i0 = i; // 子数组不能包含 nums[i0]
            }
            ans += max(min(min_i, max_i) - i0, 0);
        }
        return ans;
    }
};
