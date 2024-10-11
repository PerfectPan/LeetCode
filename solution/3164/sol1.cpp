class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> mp;
        for (const auto& num: nums1) {
            mp[num]++;
        }

        int mx = *max_element(nums1.begin(), nums1.end());

        long long ans = 0;
        for (const auto& num: nums2) {
            if (k * num == 1) {
                ans += nums1.size();
            } else {
                for (int x = k * num; x <= mx; x += k * num) {
                    if (mp.count(x)) {
                        ans += mp[x];
                    }
                }
            }
        }

        return ans;
    }
};
