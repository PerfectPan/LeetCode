class Solution {
public:
    #define N 16
    #define MP make_pair
    int dp[1<<N][N],id[105][105],cnt=0,cnt2=0,dis[N],dis2[N][N],dis3[N],dis4[44];
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    bool vis[105][105];
    vector<pair<int,int> >vec;
    struct Node{
        int x,y,step;
    };
    void init(int n,int m){
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                vis[i][j]=0;
            }
        }
    }
    int minimalSteps(vector<string>& maze) {
        int sx,sy,ex,ey;
        int n=(int)maze.size(),m=(int)maze[0].size();
        for (int i=0;i<(int)maze.size();++i){
            for (int j=0;j<(int)maze[i].size();++j){
                if (maze[i][j]=='S') sx=i,sy=j;
                else if (maze[i][j]=='T') ex=i,ey=j;
                else if (maze[i][j]=='O') vec.push_back(MP(i,j)),id[i][j]=cnt2++;
                else if (maze[i][j]=='M') id[i][j]=cnt++;
            }
        }
        if (cnt==0){
            init(n,m);
            queue<Node>Q;
            Q.push((Node){sx,sy,0});
            vis[sx][sy]=1;
            while (!Q.empty()){
                Node cur = Q.front();Q.pop();
                int x=cur.x,y=cur.y,step=cur.step;
                if (x==ex && y==ey) return step;
                for (int j=0;j<4;++j){
                    int tx=dx[j]+x;
                    int ty=dy[j]+y;
                    if (tx<0 || tx>=n || ty<0 || ty>=m || vis[tx][ty] || maze[tx][ty]=='#') continue;
                    Q.push((Node){tx,ty,step+1});
                    vis[tx][ty]=1;
                }
            }
            return -1;
        }
        vec.push_back(MP(ex,ey));
        for (int i=0;i<cnt;++i){
            for (int j=0;j<cnt;++j){
                dis2[i][j]=1000000000;
                if (i==j) dis2[i][j]=0;
            }
        }
        int limit=(1<<cnt)-1;
        for (int S=0;S<=limit;++S){
            for (int i=0;i<cnt;++i){
                dp[S][i]=1000000000;
            }
        }
        init(n,m);
        for (int j=0;j<cnt;++j) dis[j]=dis4[j]=1000000000;
        queue<Node>Q;
        Q.push((Node){sx,sy,0});
        vis[sx][sy]=1;
        while (!Q.empty()){
            Node cur = Q.front();Q.pop();
            int x=cur.x,y=cur.y,step=cur.step;
            for (int j=0;j<4;++j){
                int tx=dx[j]+x;
                int ty=dy[j]+y;
                if (tx<0 || tx>=n || ty<0 || ty>=m || vis[tx][ty] || maze[tx][ty]=='#') continue;
                Q.push((Node){tx,ty,step+1});
                vis[tx][ty]=1;
                if (maze[tx][ty]=='O'){
                    dis4[id[tx][ty]]=step+1;
                }
            }
        }
        for (int i=0;i<(int)vec.size();++i){
            init(n,m);
            for (int j=0;j<cnt;++j) dis[j]=1000000000;
            queue<Node>Q;
            Q.push((Node){vec[i].first,vec[i].second,0});
            vis[vec[i].first][vec[i].second]=1;
            while (!Q.empty()){
                Node cur = Q.front();Q.pop();
                int x=cur.x,y=cur.y,step=cur.step;
                for (int j=0;j<4;++j){
                    int tx=dx[j]+x;
                    int ty=dy[j]+y;
                    if (tx<0 || tx>=n || ty<0 || ty>=m || vis[tx][ty] || maze[tx][ty]=='#') continue;
                    Q.push((Node){tx,ty,step+1});
                    vis[tx][ty]=1;
                    if (maze[tx][ty]=='M'){
                        dis[id[tx][ty]]=step+1;
                    }
                }
            }
            if (i<(int)vec.size()-1){
                for (int j=0;j<cnt;++j){
                    for (int k=0;k<cnt;++k){
                        dis2[j][k]=min(dis2[j][k],dis[j]+dis[k]);
                    }
                }
                for (int j=0;j<cnt;++j) dp[1<<j][j]=min(dp[1<<j][j],dis[j]+dis4[i]);
            }
            else if (i==(int)vec.size()-1){
                for (int j=0;j<cnt;++j) dis3[j]=dis[j];          
            }
        }
        for (int S=1;S<=limit;++S){
            int bit=__builtin_popcount(S);
            if (bit<=1) continue;
            for (int i=0;i<cnt;++i)if(S&(1<<i)){
                for (int j=0;j<cnt;++j)if(i!=j && (S&(1<<j))){
                    dp[S][i]=min(dp[S][i],dp[S^(1<<i)][j]+dis2[j][i]);
                }
            }
        }
        int ans=1000000000;
        for (int i=0;i<cnt;++i){
            ans=min(ans,dp[limit][i]+dis3[i]);
        }
        return ans==1000000000?-1:ans;
    }
};

