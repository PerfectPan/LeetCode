class Solution {
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    bool vis[505][505];
    void dfs(int x,int y,vector<vector<char>>&g,int n,int m){
        vis[x][y]=1;
        for (int i=0;i<4;++i){
            int tx=x+dx[i];
            int ty=y+dy[i];
            if (tx<0 || tx>=n || ty<0 || ty>=m || vis[tx][ty] || g[tx][ty]=='0') continue;
            dfs(tx,ty,g,n,m);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for (int i=0;i<(int)grid.size();++i){
            for (int j=0;j<(int)grid[i].size();++j)if(!vis[i][j] && grid[i][j]=='1'){
                ans++;
                dfs(i,j,grid,(int)grid.size(),(int)grid[0].size());
            }
        }
        return ans;
    }
};

