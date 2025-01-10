class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            ans += nums[i] != nums[i - 1];
            nums[ans - 1] = nums[i];
        }
        return ans;
    }
};
