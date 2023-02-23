class Solution {
public:
    bool flag=0;
    int vis[(1<<16)+10];
    void dfs(int idx,int x,int limit,int n,vector<int>&res){
        if (flag) return;
        if (idx==limit){
            flag=1;
            return;
        }
        for (int j=0;j<n;++j){
            if (!vis[x^(1<<j)]){
                if (idx==limit-1)if(__builtin_popcount(res[0]^(x^(1<<j)))!=1)return;
                vis[x^(1<<j)]=1;
                res.push_back(x^(1<<j));
                dfs(idx+1,x^(1<<j),limit,n,res);
                if (flag)return;
                res.pop_back();
                vis[x^(1<<j)]=0;
            }
        }
    }
    vector<int> circularPermutation(int n, int start) {
        int limit=1<<n;
        vector<int>res;res.push_back(start);vis[start]=1;
        dfs(1,start,limit,n,res);
        return res;
    }
};
