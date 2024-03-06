class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < 31; ++i) {
            int cnt = 0;
            for (int& num: nums) {
                cnt += (num & (1 << i)) ? 1 : 0;
            }
            res |= cnt >= k ? (1 << i) : 0;
        }
        return res;
    }
};
