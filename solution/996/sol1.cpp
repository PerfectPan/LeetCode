class Solution {
public:
    int ans,a[13];
    bool vis[13];
    bool work(int x,int y){
        if (sqrt(x+y)==(int)sqrt(x+y)) return 1;
        return 0;
    }
    void dfs(int idx,int tot,const vector<int>&vec){
        if (idx==tot) ans++;
        set<int>S;
        for (int i=0;i<(int)vec.size();++i)if(!vis[i]){
            if (idx==-1){
                if (S.find(vec[i])==S.end()){
                    S.insert(vec[i]);
                    a[idx+1]=vec[i];
                    vis[i]=1;
                    dfs(idx+1,tot,vec);
                    vis[i]=0;
                }   
            }
            else{
                if (work(a[idx],vec[i]) && S.find(vec[i])==S.end()){
                    S.insert(vec[i]);
                    a[idx+1]=vec[i];
                    vis[i]=1;
                    dfs(idx+1,tot,vec);
                    vis[i]=0;
                }
            }
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        dfs(-1,(int)A.size()-1,A);
        return ans;
    }
};

