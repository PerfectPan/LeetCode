class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (2 * nums[i] + 2 * nums[i + 2] == nums[i + 1]) {
                cnt++;
            }
        }
        return cnt;
    }
};
