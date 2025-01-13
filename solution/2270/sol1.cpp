class Solution {
public:
    using ll = long long;
    int waysToSplitArray(vector<int>& nums) {
        ll pre = 0, sum = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            pre += nums[i];
            if (pre >= sum - pre) {
                ans++;
            }
        }
        return ans;
    }
};
