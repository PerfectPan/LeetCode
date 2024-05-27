class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int rem = mean * (n + rolls.size()) - reduce(rolls.begin(), rolls.end());
        if (rem < n or rem > n * 6) {
            return {};
        }
        int avg = rem / n, extra = rem % n;
        vector<int> ans(extra, avg + 1);
        ans.insert(ans.end(), n - extra, avg);
        return ans;
    }
};
