class Solution {
public:
    #define N 100010
    int dp[N][3];
    int minimumOperations(string leaves) {
        memset(dp,0x3f3f3f3f,sizeof(dp));
        dp[0][0]=leaves[0]=='y';
        for (int i=1;i<leaves.size();++i){
            char ch=leaves[i];
            dp[i][0]=dp[i-1][0]+(ch=='y');
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+(ch=='r');
            dp[i][2]=min(dp[i-1][1],dp[i-1][2])+(ch=='y');
        }
        return dp[(int)leaves.size()-1][2];
    }
};

