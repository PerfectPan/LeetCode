class Solution {
public:
    int cnt=0,digit[20],dp[20][20];
    int dfs(int x,int num,bool jud){
        if (x==0) return num;
        if (!jud && ~dp[x][num]) return dp[x][num];
        int limit=jud?digit[x]:9;
        int ret=0;
        for (int i=0;i<=limit;++i){
            ret+=dfs(x-1,num+(i==1),jud && (i==limit));
        }
        if (!jud) dp[x][num]=ret;
        return ret;
    }
    int get(int x){
        while (x){
            digit[++cnt]=x%10;
            x/=10;
        }
        return dfs(cnt,0,1);
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        return get(n);
    }
};
