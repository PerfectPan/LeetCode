class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for (auto& [_, v]: mp) {
            if (v.size() == 1) {
                ans = min(ans, n / 2);
            } else {
                int dis = v[0] + n - v.back();
                for (int i = 1; i < v.size(); ++i) {
                    dis = max(dis, v[i] - v[i - 1]);
                }
                ans = min(ans, dis / 2);
            }
        }
        return ans;
    }
};
