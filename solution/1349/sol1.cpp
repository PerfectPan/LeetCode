class Solution {
public:
    int f[8][1<<8];
    bool vis[1<<8];
    bool check(int bit,int A,int B){
        for (int i=0;i<bit;++i)if(A&(1<<i)){
            if ((i-1>=0 && (B&(1<<(i-1))))||(i+1<bit && (B&(1<<(i+1))))) return false;
        }
        return true;
    }
    int maxStudents(vector<vector<char>>& seats) {
        int n=(int)seats.size(),m=(int)seats[0].size();
        int S=1<<m;
        memset(vis,0,sizeof(vis));
        for (int i=0;i<S;++i){
            bool flag=1;
            for (int j=0;j<(int)seats[0].size();++j){
                if (i&(1<<j)){
                    if ((j-1>=0 && (i&(1<<(j-1)))) || (j+1<m && (i&(1<<(j+1))))){
                        flag=0;
                        break;
                    }
                }
            }
            vis[i]=flag;
        }
        for (int i=0;i<n;++i){
            for (int j=0;j<S;++j)if(vis[j]){
                bool flag=1;
                for (int k=0;k<m;++k){
                    if ((j&(1<<k)) && seats[i][k]=='#'){
                        flag=0;
                        break;
                    }
                }
                int num=__builtin_popcount(j);
                if (flag){
                    if (i==0) f[i][j]=num;
                    else{
                        for (int k=0;k<S;++k){
                            if (check(m,j,k)) f[i][j]=max(f[i][j],f[i-1][k]+num);
                        }
                    }
                }
            }
        }
        int ans=0;
        for (int i=0;i<S;++i) ans=max(ans,f[n-1][i]);
        return ans;
    }
};
