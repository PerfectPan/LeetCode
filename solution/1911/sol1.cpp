class Solution {
public:
    long long dp[100010][2];
    long long maxAlternatingSum(vector<int>& nums) {
        // 0 偶数
        // 1 奇数
        // dp[i][0]=max(dp[i-1][0],dp[i-1][1]+nums[i])
        // dp[i][1]=max(dp[i-1][1],dp[i-1][0]-nums[i])
        // dp[0][0]=nums[0];
        // dp[0][1]=-inf
        dp[0][0]=nums[0];
        dp[0][1]=-100000000000LL;
        int n=nums.size();
        for (int i=1;i<nums.size();++i){
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1]+nums[i],1LL*nums[i]));
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-nums[i]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};

