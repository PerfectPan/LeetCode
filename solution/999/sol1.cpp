class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int cnt=0,st=0,ed=0;
        for (int i=0;i<8;++i)for (int j=0;j<8;++j){
            if (board[i][j]=='R') st=i,ed=j;
        }
        for (int i=0;;i++){
            if (st+i>=8 || board[st+i][ed]=='B') break;
            if (board[st+i][ed]=='p'){
                cnt++;
                break;
            }
        }
        for (int i=0;;i--){
            if (st+i<0 || board[st+i][ed]=='B') break;
            if (board[st+i][ed]=='p'){
                cnt++;
                break;
            }
        }
        for (int i=0;;i++){
            if (ed+i>=8 || board[st][ed+i]=='B') break;
            if (board[st][ed+i]=='p'){
                cnt++;
                break;
            }
        }
        for (int i=0;;i--){
            if (ed+i<0 || board[st][ed+i]=='B') break;
            if (board[st][ed+i]=='p'){
                cnt++;
                break;
            }
        }
        return cnt;
    }
};

