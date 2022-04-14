class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>Q;
        int t[20][20];
        int dir_x[]={0,1,0,-1};
        int dir_y[]={1,0,-1,0};
        memset(t,-1,sizeof(t));
        for (int i=0;i<(int)grid.size();++i){
            for (int j=0;j<(int)grid[i].size();++j){
                if (grid[i][j]==2){
                    Q.push(make_pair(i,j));
                    t[i][j]=0;
                }
            }
        }
        while (!Q.empty()){
            pair<int,int> x=Q.front();Q.pop();
            for (int i=0;i<4;++i){
                int tx=x.first+dir_x[i];
                int ty=x.second+dir_y[i];
                if (tx<0||tx>=(int)grid.size()||ty<0||ty>=(int)grid[0].size()||t[tx][ty]!=-1||grid[tx][ty]==0) continue;
                t[tx][ty]=t[x.first][x.second]+1;
                Q.push(make_pair(tx,ty));
            }
        }
        int ans=0;
        for (int i=0;i<(int)grid.size();++i){
            for (int j=0;j<(int)grid[i].size();++j){
                if (grid[i][j]!=0){
                    if (t[i][j]==-1) return -1;
                    ans=max(ans,t[i][j]);
                }
            }
        }
        return ans;
    }
};

