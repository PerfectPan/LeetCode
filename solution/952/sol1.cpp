class Solution {
public:
    int cnt[100010],ans[100010],fa[100010];
    int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
    int largestComponentSize(vector<int>& A) {
        for (int i=0;i<(int)A.size();++i) cnt[A[i]]+=1;
        for (int i=1;i<=100000;++i) fa[i]=i;
        for (int i=2;i<=100000;++i){
            for (int j=i;j<=100000;j+=i)if(cnt[j]){
                int tx=Find(i),ty=Find(j);
                if (tx^ty) fa[tx]=ty;
            }
        }
        for (int i=1;i<=100000;++i)if(cnt[i]){
            ans[Find(i)]+=cnt[i];
        }
        return *max_element(ans+1,ans+1+100000);
    }
};

