class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int mx = -1, ans = -1;
        for (int div: divisors) {
            int cnt = 0;
            for (int num: nums) {
                cnt += num % div == 0;
            }
            if (cnt > mx) {
                mx = cnt;
                ans = div;
            } else if (cnt == mx) {
                ans = min(ans, div);
            }
        }
        return ans;
    }
};
