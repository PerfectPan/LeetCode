class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> f(n, 1), path(n, -1);
        int mx = 1, idx = 0;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 and f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                    path[i] = j;
                }
            }
            if (mx < f[i]) {
                mx = f[i];
                idx = i;
            }
        }

        vector<int> ans;
        for (int i = idx; i >= 0; i = path[i]) {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};
