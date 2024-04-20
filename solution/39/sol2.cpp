class Solution {
public:
    vector<vector<int>> res;
    void dfs(int idx, int sum, vector<int>& ans, vector<int>& candidates, int target) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(ans);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            ans.push_back(candidates[i]);
            dfs(i, sum + candidates[i], ans, candidates, target);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        dfs(0, 0, ans, candidates, target);
        return res;
    }
};
