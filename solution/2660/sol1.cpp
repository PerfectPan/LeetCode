class Solution {
public:
    int getScore(const vector<int>& player) {
        int score = 0, n = player.size();
        for (int i = 0; i < n; ++i) {
            if (i >= 1 && (player[max(0, i - 1)] == 10 || player[max(0, i - 2)] == 10)) {
                score += player[i] * 2;
            } else {
                score += player[i];
            }
        }
        return score;
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = getScore(player1), score2 = getScore(player2);
        if (score1 > score2) {
            return 1;
        }
        if (score1 < score2) {
            return 2;
        }
        return 0;
    }
};
