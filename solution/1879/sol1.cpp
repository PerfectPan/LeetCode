class Solution {
public:
    int N = 14;
    int dp[1<<14];
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        int n = nums2.size();
        int t = 1<<n;
        for (int S=1;S<t;++S){
            int x = __builtin_popcount(S);
            for (int i=0;i<n;++i)if(S&(1<<i)){
                if (~dp[S^(1<<i)]){
                    if (dp[S] == -1) {
                        dp[S] = dp[S^(1<<i)] + (nums2[i] ^ nums1[x-1]);
                    } else {
                        dp[S] = min(dp[S],dp[S^(1<<i)] + (nums2[i] ^ nums1[x-1]));
                    }
                }
            }
        }
        return dp[t-1];
    }
};

