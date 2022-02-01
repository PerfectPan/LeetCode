class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n + 2), right(n + 2);
        left[0] = 0;
        for (int i = 0; i < n; ++i) {
            left[i + 1] = left[i] + (nums[i] == 0);
        }
        right[n + 1] = 0;
        for (int i = n - 1; i >= 0; --i) {
            right[i + 1] = right[i + 2] + (nums[i] == 1);
        }
        vector<int> res; 
        int ans = 0;
        for (int i = 1; i <= n + 1; ++i) {
            ans = max(ans, left[i - 1] + right[i]);
        }
        for (int i = 1; i <= n + 1; ++i) {
            if (ans == left[i - 1] + right[i]) {
                res.emplace_back(i - 1);
            }
        }
        return res;
    }
};

