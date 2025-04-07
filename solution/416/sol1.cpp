class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int V = sum / 2;
        vector<int> f(V + 1, 0);
        f[0] = 1;
        for (int& num: nums) {
            for (int i = V; i >= num; --i) {
                f[i] |= f[i - num];
            }
        }
        return f[V];
    }
};
