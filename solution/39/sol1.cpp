class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine,int idx) {
        if (target <= 0 || idx == candidates.size()) {
            if (target == 0) {
                ans.push_back(combine);
            }
            return;
        }
        dfs(candidates, target, ans, combine, idx + 1);
        int i = 1;
        for (; target - i * candidates[idx] >= 0; ++i) {
            combine.push_back(candidates[idx]);
            dfs(candidates, target - i * candidates[idx], ans, combine, idx + 1);
        }
        for (; i > 1; --i) {
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> t;
        dfs(candidates, target, ans, t, 0);
        return ans;
    }
};

