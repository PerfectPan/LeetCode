class Solution {
public:
    bool check(string a,string b){
        for (int i=(int)a.length()-1,j=(int)b.length()-1;j>=0;--j,--i){
            if (a[i]!=b[j]) return 0;
        }
        return 1;
    }
    int minimumLengthEncoding(vector<string>& words) {
        int n=(int)words.size();
        if (!n) return 0;
        vector<int>id(n, 0);
        for (int i=0;i<n;++i) id[i]=i;
        sort(id.begin(), id.end(), [&](int x, int y) {
            return words[x].length() > words[y].length();
        });
        vector<int>vis(n,0);
        int ans=0;
        for (int i=0;i<n;++i)if(!vis[id[i]]){
            vis[id[i]]=1;
            ans+=(int)words[id[i]].length()+1;
            for (int j=i+1;j<n;++j)if(!vis[id[j]]){
                if (check(words[id[i]],words[id[j]])){
                    vis[id[j]]=1;
                }
            }
        }
        return ans;
    }
};

