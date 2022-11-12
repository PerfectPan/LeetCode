class Solution {
public:
    using ll = long long;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int> res(100010, 0);
        int t = 0;
        ll sum = 0;
        ll maxSum = 0;
        for (int i = 0; i < k; ++i) {
            if (++res[nums[i]] == 1) {
                t++;
            }
            sum += nums[i];
        }
        if (t == k) {
            maxSum = sum;
        }

        for (int i = k; i < nums.size(); ++i) {
            if (--res[nums[i - k]] == 0) {
                t--;
            }
            sum -= nums[i - k];
            if (++res[nums[i]] == 1) {
                t++;
            }
            
            sum += nums[i];

            if (t == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;

    }
};
