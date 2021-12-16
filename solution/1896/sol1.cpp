class Solution {
public:
    int cnt=0;
    #define N 100010
    struct Node {
        int tp;
        int val;
    }t[N];
    vector<int> G[N];
    int DP[N][2];
    void dp(int root) {
        if (G[root].size()==0){
            DP[root][0]=t[root].val!=0;
            DP[root][1]=t[root].val!=1;
            return;
        }
        int l=G[root][0],r=G[root][1];
        dp(l),dp(r);
        // &
        if (t[root].tp==0){
            DP[root][0]=min(DP[l][1]+DP[r][0],min(DP[l][0]+DP[r][1],DP[l][0]+DP[r][0]));
            DP[root][1]=min(DP[l][1]+DP[r][0]+1,min(DP[l][0]+DP[r][1]+1,DP[l][1]+DP[r][1]));
        } else {
            // |
            DP[root][0]=min(DP[l][1]+DP[r][0]+1,min(DP[l][0]+DP[r][1]+1,DP[l][0]+DP[r][0]));
            DP[root][1]=min(DP[l][1]+DP[r][0],min(DP[l][0]+DP[r][1],DP[l][1]+DP[r][1]));
        }
    }
    vector<int>nums;
    vector<char>ops;
    vector<char>S;
    int grade(char op){
        switch (op){
            case '(':return 1;
            case '|':
            case '&':return 2;
        }
        return 0;
    }
    void calc(char op){
        int y=*nums.rbegin();
        nums.pop_back();
        int x=*nums.rbegin();
        nums.pop_back();
        int z;
        switch (op){
            case '|':z=x|y;
                    break;
            case '&':z=x&y;
                    break;
        }
        nums.push_back(z);
    }
    int solve(string s){ 
        int top=0,val=0;
        for (int i=0;i<(int)s.length();i++){
            if (s[i]=='0'||s[i]=='1'){
                val=s[i]-'0';
                nums.push_back(val);
                S.emplace_back(s[i]);
                // printf("%d",val);
                // val=0;
            }
            else if (s[i]=='(') ops.push_back(s[i]);
            else if (s[i]==')'){
                while (*ops.rbegin()!='('){
                    calc(*ops.rbegin());
                    S.emplace_back(*ops.rbegin());
                    // printf("%c",*ops.rbegin());
                    ops.pop_back();
                }
                ops.pop_back();
            }
            else{
                while (ops.size()&&grade(*ops.rbegin())>=grade(s[i])){
                    calc(*ops.rbegin());
                    // printf("%c",*ops.rbegin());
                    S.emplace_back(*ops.rbegin());
                    ops.pop_back();
                }
                ops.push_back(s[i]);
            }
        }
        while (ops.size()){
            calc(*ops.rbegin());
            // printf("%c",*ops.rbegin());
            S.emplace_back(*ops.rbegin());
            ops.pop_back();
        }
        // puts("");
        return *nums.begin();
    }
    pair<int,int> dfs(string& exp,int l,int r) {
        // cout<<l<<" "<<r<<endl;
        if (l==r){
            t[cnt++]=(Node){3,exp[l]-'0'};
            return {cnt-1,exp[l]-'0'};
        }
        int A=-1, O=-1, p=0;  
        for (int i=r;i>=l;--i){
            switch (exp[i]){
                case '(':
                    p--;
                    break;
                case ')':
                    p++;
                    break;
                case '&':
                    if (!p){
                        A=i;
                        i=l-1;           
                    }
                    break;
                case '|':
                    if (!p){
                        O=i;  
                        i=l-1;
                    }
                    break;
            }
        }
        if (A<0&&O<0){
            int i,j;
            for (i=l,j=r;i<j;++i,--j){
                if (exp[i]=='(' && exp[j]==')') continue;
                break;
            }
            if (i==l) i++,j--;
            // cout<<i<<" "<<j<<endl;
            return dfs(exp,i,j);
        }
        int id=cnt++;
        t[id]=(Node){A>O?0:1,-1};
        
        pair<int,int> L=dfs(exp,l,A>O?A-1:O-1);
        pair<int,int> R=dfs(exp,A>O?A+1:O+1,r);
        G[id].emplace_back(L.first);
        G[id].emplace_back(R.first);
        // cout<<id<<" "<<(A>0?'&':'|')<<" "<<(A>0?A:O)<<" "<<l<<" "<<r<<endl;
        int Val=A>O?(L.second & R.second) :(L.second | R.second);
        return {id,Val};
    }
    int minOperationsToFlip(string expression) {
        // pair<int,int> rt=dfs(expression,0,(int)expression.size()-1);
        // dp(rt.first);
        int res = solve(expression);
        // for (auto& ch: S){
        //     putchar(ch);
        // }
        // puts("");
        stack<int> c;
        for (int i=0;i<S.size();++i){
            if (S[i]=='0'||S[i]=='1'){
                t[cnt++]=(Node){3,S[i]-'0'};
                c.push(cnt-1);
            }else{
                t[cnt++]=(Node){S[i]=='&'?0:1,-1};
                int R=c.top();c.pop();
                int L=c.top();c.pop();
                G[cnt-1].emplace_back(L);
                G[cnt-1].emplace_back(R);
                c.push(cnt-1);
                // cout<<cnt-1<<" "<<S[i]<<" "<<L<<" "<<t[L].val<<" "<<R<<" "<<t[R].val<<endl;
            }
        }
        int rt=c.top();
        dp(rt);
        return DP[rt][!res];
    }
};

