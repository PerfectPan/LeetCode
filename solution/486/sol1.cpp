class Solution {
public:
    int dp[100][100];
    int sum[100];
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;++i){
            dp[i+1][i+1]=nums[i];
            sum[i+1]=sum[i]+nums[i];
        }
        for (int len=2;len<=n;++len){
            for (int l=1;l+len-1<=n;++l){
                int r=l+len-1;
                dp[l][r]=max(sum[r-1]-sum[l-1]-dp[l][r-1]+nums[r-1],sum[r]-sum[l]-dp[l+1][r]+nums[l-1]);
            }
        }
        return dp[1][n]>=sum[n]-dp[1][n];
    }
};

