// dp[k][l][r] 表示 [l, r] 还剩 k 块披萨的最大值
// 对于环的问题，把数组复制一倍即可，最后答案是 dp[0][i][i + n - 1]
class Solution {
    int dp[3][1020][1020];
public:
    int maxSizeSlices(vector<int>& slices) {
        int n=(int)slices.size();
        int len=n*2;
        for (int i=0;i<n;++i) slices.push_back(slices[i]);
        for (int i=1;i<=len;++i)for(int j=i;j<=len;++j) for(int k=0;k<3;++k)dp[k][i][j]=-1;
        for (int i=1;i<=len;++i) dp[1][i][i]=0,dp[2][i][i+1]=0;
        int ans=0;
        for (int i=3;i<=n;i+=3){
            for (int l=1;l+i-1<=len;++l){
                int r=l+i-1;
                for (int k=l+1;k<=r-1;++k){
                    if (~dp[1][l][k-1] && ~dp[1][k+1][r]) dp[0][l][r]=max(dp[0][l][r],dp[1][l][k-1]+dp[1][k+1][r]+slices[k-1]);
                    k++;
                    if (k>r-1) break;
                    if (~dp[2][l][k-1] && ~dp[0][k+1][r]) dp[0][l][r]=max(dp[0][l][r],dp[2][l][k-1]+dp[0][k+1][r]+slices[k-1]);
                    k++; 
                    if (k>r-1) break;
                    if (~dp[0][l][k-1] && ~dp[2][k+1][r]) dp[0][l][r]=max(dp[0][l][r],dp[0][l][k-1]+dp[2][k+1][r]+slices[k-1]);               
                }
                r++;
                dp[1][l][r]=max(dp[0][l][r-1],dp[0][l+1][r]);
                for (int k=l+1;k<=r-1;++k){
                    if (~dp[0][l][k-1] && ~dp[0][k+1][r]) dp[1][l][r]=max(dp[1][l][r],dp[0][l][k-1]+dp[0][k+1][r]);
                }    
                r++;
                for (int k=l;k<=r-1;++k){
                    if (~dp[1][l][k] && ~dp[1][k+1][r]) dp[2][l][r]=max(dp[2][l][r],dp[1][l][k]+dp[1][k+1][r]);
                    k++;
                    if (k>r-1) break;
                    if (~dp[2][l][k] && ~dp[0][k+1][r]) dp[2][l][r]=max(dp[2][l][r],dp[2][l][k]+dp[0][k+1][r]);
                    k++;
                    if (k>r-1) break;
                    if (~dp[0][l][k] && ~dp[2][k+1][r]) dp[2][l][r]=max(dp[2][l][r],dp[0][l][k]+dp[2][k+1][r]);
                }    
                if (i==n) ans=max(ans,dp[0][l][l+n-1]);
            }
        }
        return ans;
    }
};
