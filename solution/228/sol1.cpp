// 按题意模拟即可，时间复杂度 O(n)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int l = 0;
        int i = 0, n = nums.size();
        while (i < n) {
            int l = i;
            while (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
                i += 1;
            }
            int r = i;
            string res = to_string(nums[l]);
            if (l < r) {
                res.append("->");
                res.append(to_string(nums[r]));
            }
            ans.push_back(move(res));
            i += 1;
        }
        return ans;
    }
};
