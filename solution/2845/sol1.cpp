class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        int pre = 0;
        for (int num: nums) {
            if (num % modulo == k) {
                pre++;
                pre %= modulo;
            }
            int right = (pre - k + modulo) % modulo;
            ans += mp[right];
            mp[pre]++;
        }

        return ans;
    }
};
