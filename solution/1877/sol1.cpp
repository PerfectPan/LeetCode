class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for (int i = 0, j = (int)nums.size() - 1; i < j; ++i, --j) {
            ans = max(ans, nums[i] + nums[j]);
        }
        return ans;
    }
};

