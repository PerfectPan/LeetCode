const int maxn = 300000 + 5;
namespace pam {
int sz, tot, last,mx;
int cnt[maxn], ch[maxn][26], len[maxn], fail[maxn];
char s[maxn];
int node(int l) {
  sz++;
  memset(ch[sz], 0, sizeof(ch[sz]));
  len[sz] = l;
  if (l&1) mx=max(mx,l);
  fail[sz] = cnt[sz] = 0;
  return sz;
}
void clear() {
  sz = -1;
  last = 0;
  s[tot = 0] = '$';
  node(0);
  node(-1);
  fail[0] = 1;
  mx=0;
}
int getfail(int x) {
  while (s[tot - len[x] - 1] != s[tot]) x = fail[x];
  return x;
}
void insert(char c) {
  s[++tot] = c;
  int now = getfail(last);
  if (!ch[now][c - 'a']) {
    int x = node(len[now] + 2);
    fail[x] = ch[getfail(fail[now])][c - 'a'];
    ch[now][c - 'a'] = x;
  }
  last = ch[now][c - 'a'];
  cnt[last]++;
}
}  // namespace pam
class Solution {
public:
    long long maxProduct(string a) {
        int n=a.length();
        pam::clear();
        vector<int> L(n,0),R(n,0);
        for (int i=0;i<a.length();++i){
            pam::insert(a[i]);
            L[i]=pam::mx;
        }
        
        pam::clear();
        for (int i=a.length()-1;i>=0;--i){
            pam::insert(a[i]);
            R[i]=pam::mx;
        }
        for (int i=1;i<a.length();++i){
            L[i]=max(L[i],L[i-1]);
        }
        for (int i=a.length()-2;i>=0;--i){
            R[i]=max(R[i],R[i+1]);
        }
        long long ans=0;
        for (int i=1;i<n;++i){
            ans=max(ans,1LL*L[i-1]*R[i]);
        }
        return ans;
    }
};

