class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = 1;
        int mx = INT_MIN, idx = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num < 0 and mx < num) {
                mx = num;
                idx = i;
            }
            if (num < 0) {
                cnt++;
            }
        }

        int zero = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                ans = ans * nums[i];
                continue;
            }
            if (nums[i] == 0) {
                zero++;
                continue;
            }
            if (cnt % 2 == 1 && i == idx) {
                continue;
            }
            ans = ans * nums[i];
        }
        if (zero == nums.size()) {
            return 0;
        }
        if (zero + cnt == nums.size()) {
            if (zero > 0 && cnt == 1) {
                return 0;
            }
            if (zero == 0 && cnt == 1) {
                return nums[idx];
            }
        }
        return ans;   
    }
};
