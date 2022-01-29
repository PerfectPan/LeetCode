class Solution {
public:
    #define N 110
    int dp[N][N];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        if (!n) return 0;
        int m=obstacleGrid[0].size();
        dp[0][0]=1;
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                    if (i>0) dp[i][j]+=dp[i-1][j];
                    if (j>0) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};

