class Solution {
public:
    int dir_x[4]={0,1,0,-1};
    int dir_y[4]={1,0,-1,0};
    bool ok(int x,int y,vector<vector<char>>& board,int n,int m){
        board[x][y]='Y';
        bool flag=0;
        for (int i=0;i<4;++i){
            int tx=dir_x[i]+x;
            int ty=dir_y[i]+y;
            if (tx<0||tx>=n||ty<0||ty>=m||board[tx][ty]!='O') continue;
            if (tx==0||tx==n-1||ty==0||ty==m-1) flag=1;
            flag|=ok(tx,ty,board,n,m);
        }
        return flag;
    }
    void dfs(int x,int y,vector<vector<int>>& vis, vector<vector<char>>& board,int n,int m,char ch){
        board[x][y]=ch;
        vis[x][y]=1;
        for (int i=0;i<4;++i){
            int tx=dir_x[i]+x;
            int ty=dir_y[i]+y;
            if (tx<0||tx>=n||ty<0||ty>=m||vis[tx][ty]||board[tx][ty]!='Y') continue;
            dfs(tx,ty,vis,board,n,m,ch);
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size()==0) return;
        int n=board.size(),m=board[0].size();
        vector<vector<int> > vis(n, vector<int>(m,0));
        for (int i=1;i<n-1;++i){
            for (int j=1;j<m-1;++j)if(!vis[i][j]&&board[i][j]=='O'){
                bool f=ok(i,j,board,n,m);
                dfs(i,j,vis,board,n,m,f?'O':'X');
            }
        }
    }
};

