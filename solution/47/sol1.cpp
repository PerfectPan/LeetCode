class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, int idx) {
        if (idx == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        unordered_set<int> S;
        for (int i = idx; i < (int)nums.size(); ++i) if (S.find(nums[i]) == S.end()){
            S.insert(nums[i]);
            swap(nums[idx], nums[i]);
            dfs(nums, ans, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(nums, ans, 0);
        return ans;
    }
};

