// 按题意贪心的模拟，维护 5 个字母的队列，然后不断依次出一轮队头即可
class Solution {
public:
    #define N 100010
    int nxt[N][26],cnt[N];
    bool vis[N];
    queue<int>Q[5];
    int minNumberOfFrogs(string croakOfFrogs) {
        int i,j,n=(int)croakOfFrogs.size();
        memset(cnt,0,sizeof(cnt));
        string s="croak";
        for (int i=0;i<(int)croakOfFrogs.size();++i){
            if (croakOfFrogs[i]=='c') Q[0].push(i+1);
            else if (croakOfFrogs[i]=='r') Q[1].push(i+1);
            else if (croakOfFrogs[i]=='o') Q[2].push(i+1);
            else if (croakOfFrogs[i]=='a') Q[3].push(i+1);
            else if (croakOfFrogs[i]=='k') Q[4].push(i+1);
            else return -1;
        }
        int nn=n;
        for (;;){
            if (Q[0].empty()){
                if (n==0) break;
                return -1;
            }
            int pre=Q[0].front();Q[0].pop();
            if (Q[1].empty()) return -1;
            int r=Q[1].front();Q[1].pop();
            if (Q[2].empty()) return -1;
            int o=Q[2].front();Q[2].pop();
            if (Q[3].empty()) return -1;
            int a=Q[3].front();Q[3].pop();
            if (Q[4].empty()) return -1;
            int k=Q[4].front();Q[4].pop();
            if (pre<r && r<o && o<a && a<k){
                cnt[pre]++;cnt[k+1]--;
                n-=5;
            }
            else return -1;
        }
        int ans=cnt[1];
        for (int i=2;i<=nn;++i){
            cnt[i]+=cnt[i-1];
            ans=max(ans,cnt[i]);
        }
        return ans;
    }
};
