class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> ans;
        vector<int> pre(n, 0);

        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + (nums[i] % 2 != nums[i - 1] % 2);
        }

        for (auto& query: queries) {
            int l = query[0], r = query[1];
            ans.push_back(pre[r] - pre[l] == r - l);
        }

        return ans;       
    }
};
