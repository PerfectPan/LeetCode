/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let cnt = 0, st = 0, ed = 0;
    const dx = [0, 1, 0, -1];
    const dy = [1, 0, -1, 0];

    for (let i = 0; i < 8; ++i) {
        for (let j = 0; j < 8; ++j) {
            if (board[i][j] == 'R') {
                st = i;
                ed = j;
                break;
            }
        }
    }
    for (let i = 0; i < 4; ++i){
        for (let step = 0;; ++step) {
            const tx = st + step * dx[i];
            const ty = ed + step * dy[i];
            if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8 || board[tx][ty] == 'B') break;
            if (board[tx][ty] == 'p') {
                cnt++;
                break;
            }
        }
    }
    return cnt;
};

