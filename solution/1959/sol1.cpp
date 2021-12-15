class Solution {
public:
    int dp[205][205];
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,0x3f,sizeof(dp));
        int n=nums.size();
        dp[0][0]=0;
        int ans=-1;
        for (int i=1;i<n;++i){
            for (int j=0;j<=min(i,k);++j){
                if (j>0){
                    dp[i][j]=dp[i-1][j-1];
                    int tot=0,c=0,mx=-1;
                    for (int l=i;l>=1;--l){
                        tot+=nums[l];
                        c++;
                        mx=max(mx,nums[l]);
                        if (dp[l-1][j-1]!=0x3f)
                        dp[i][j]=min(dp[i][j],dp[l-1][j-1]+mx*c-tot);
                    }                  
                } else {
                    int tot=0,c=0,mx=-1;
                    for (int l=i;l>=0;--l){
                        tot+=nums[l];
                        c++;
                        mx=max(mx,nums[l]);
                    }
                    dp[i][0]=mx*c-tot;
                }
                if (i==n-1){
                    if (ans==-1){
                        ans=dp[i][j];
                    }else{
                        ans=min(ans,dp[i][j]);
                    }
                }
            }
        }
        return n==1?0:ans;
    }
};

