class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        int lst = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > lst) {
                int L = 1, R = nums[i], ans = -1;
                while (L <= R) {
                    int mid = L + ((R - L) >> 1);
                    if ((nums[i] + mid - 1) / mid <= lst) {
                        ans = mid;
                        R = mid - 1;
                    } else {
                        L = mid + 1;
                    }
                }
                res += ans - 1;
                lst = nums[i] / ans;
            } else {
                lst = nums[i];
            }
        }
        return res;        
    }
};
