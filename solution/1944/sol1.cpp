// 单调栈
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        vector<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            while (stk.size() > 0 && stk.back() < heights[i]) {
                stk.pop_back();
                ans[i]++;
            }
            if (stk.size() > 0) {
                ans[i]++;
            }
            stk.push_back(heights[i]);
        }
        return ans;
    }
};
