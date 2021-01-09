class Solution {
public:
  bool vis[128];
  int numJewelsInStones(string J, string S) {
    int ans = 0;
    for (auto &ch : J) {
      vis[ch] = true;
    }
    for (auto &ch : S) {
      ans += vis[ch];
    }
    return ans;
  }
};



int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
int xxx() {
    for (int i=0;i<n;++i) fa[i]=i;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            if (G[i][j]){
                fa[Find(i)]=Find(j);
            }
        }
    }
    int ans=0;
    for (int i=0;i<n;++i){
        cnt[Find(i)]++;
        ans=max(ans,cnt[Find(i)]);
    }
    return ans;
}