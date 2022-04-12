class Solution {
public:
    int dp[400],pre[400];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for (auto x:days){
            pre[x]++;
        }
        for (int i=1;i<=365;++i) pre[i]+=pre[i-1];
        dp[0]=0;
        for (int i=1;i<=365;++i){
            dp[i]=1000000000;
            if (pre[i]-pre[i-1]>0) dp[i]=min(dp[i],dp[i-1]+costs[0]);
            else dp[i]=min(dp[i],dp[i-1]);
            if (i-7>=0) dp[i]=min(dp[i],dp[i-7]+(pre[i]-pre[i-7]>0?costs[1]:0));
            if (i-30>=0) dp[i]=min(dp[i],dp[i-30]+(pre[i]-pre[i-30]>0?costs[2]:0));
        }
        return dp[365];
    }
};

