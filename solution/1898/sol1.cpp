class Solution {
public:
    bool vis[100010];
    bool check(int k,string& s,string& p,vector<int>& r){
        for (int i=0;i<k;++i){
            vis[r[i]]=1;
        }
        bool f=0;
        int i,j;
        for (i=0,j=0;i<s.size() && j<p.size();++i){
            if (vis[i]){
                continue;
            }
            if (s[i]==p[j]){
                j++;
            }
        }
        if (j==p.size()){
            f=1;
        }
        for (int i=0;i<k;++i){
            vis[r[i]]=0;
        }
        return f;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n=removable.size();
        int l=1,r=n,ans=0;
        while (l<=r){
            int mid=l+((r-l)>>1);
            if (check(mid,s,p,removable)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};

