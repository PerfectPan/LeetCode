class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n=(int)matrix.size();
        if (!n) return vector<vector<int> >(0,vector<int>(0));
        int m=(int)matrix[0].size();
        vector<vector<int> >vec(n, vector<int>(m,0));
        queue<pair<int,int> >Q;
        vector<vector<int> >vis(n, vector<int>(m,0));
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (matrix[i][j]==0){
                    Q.push(make_pair(i,j));
                    vis[i][j]=1;
                }
            }
        }
        while (!Q.empty()){
            auto [x, y] = Q.front();Q.pop();
            for (int i=0;i<4;++i){
                int tx=dx[i]+x;
                int ty=dy[i]+y;
                if (tx<0||tx>=n||ty<0||ty>=m||vis[tx][ty])continue;
                vis[tx][ty]=1;
                vec[tx][ty]=vec[x][y]+1;
                Q.push(make_pair(tx,ty));
            }
        }
        return vec;
    }
};

