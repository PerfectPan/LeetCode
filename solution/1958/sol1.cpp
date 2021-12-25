class Solution {
public:
    int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        board[rMove][cMove] = color;
        int n = board.size();
        int m = board[0].size();

        for (int i = 0;i<8;++i){
            int tx=rMove,ty=cMove;
            int c=1;
            bool f=0;
            while (tx>=0&&tx<n&&ty>=0&&ty<m){
                tx+=dx[i];
                ty+=dy[i];
                if (tx<0||tx>=n||ty<0||ty>=m||board[tx][ty]=='.') {
                    break;
                }
                if (board[tx][ty]!=color){
                    c++;
                }else if (c>=2){
                    f=1;
                    break;
                }else{
                    break;
                }
            }
            if (f) return true;
        }
        
        return false;
    }
};

