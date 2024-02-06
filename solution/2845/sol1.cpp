class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;
        int pre = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] %= modulo;
            pre += nums[i] == k;

            int query = ((pre % modulo - k) + modulo) % modulo;
            ans = (ans + mp[query]);
            mp[pre % modulo]++;
        }   

        return ans;     
    }
};
