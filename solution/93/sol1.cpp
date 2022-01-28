class Solution {
public:
    void dfs(string s, int idx, string t, int depth, vector<string>& ans){
        if (depth>4) return;
        if (idx==s.length()){
            if (depth!=4) return;
            t.pop_back();
            ans.push_back(t);
            return;
        }
        int res=0;
        for (int i=idx;i<=idx+2 && i<s.length();++i){
            if (i==idx && s[i]=='0'){
                dfs(s,i+1,t+"0.",depth+1,ans);
                return;
            }
            res=res*10+s[i]-'0';
            if (res>=0 && res<=255){
                dfs(s,i+1,t+to_string(res)+".",depth+1,ans);
            }
            else break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(s, 0, "", 0,ans);
        return ans;
    }
};


`
