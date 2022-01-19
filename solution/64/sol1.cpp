class Solution {
public:
    int dp[205][205];
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (!n) return 0;
        int m = grid[0].size();
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                dp[i][j]=2000000000;
            }
        }
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                if (i==1 && j==1) dp[i][j]=grid[i-1][j-1];
                if (i>1){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+grid[i-1][j-1]);
                }
                if (j>1){
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+grid[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

