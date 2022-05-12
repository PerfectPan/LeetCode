class Solution {
public:
    #define N 1010
    int dp[N][N];
    int findLength(vector<int>& A, vector<int>& B) {
        int n=A.size(),m=B.size(),res=0;
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (A[i]==B[j]) dp[i+1][j+1]=dp[i][j]+1;
                else dp[i+1][j+1]=0;
                res=max(res,dp[i+1][j+1]);
            }
        }
        return res;
    }
};

