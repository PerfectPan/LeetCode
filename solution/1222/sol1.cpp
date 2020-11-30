class Solution {
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                          vector<int> &king) {
    vector<pair<int, int>> dir{{-1, -1}, {-1, 0}, {-1, 1}, {1, -1},
                               {1, 0},   {1, 1},  {0, 1},  {0, -1}};
    vector<vector<int>> isQueen(8, vector<int>(8, 0));
    for (auto &queen : queens) {
      isQueen[queen[0]][queen[1]] = 1;
    }
    int n = 8, m = 8;
    vector<vector<int>> res;
    for (auto &D : dir) {
      int dx = D.first, dy = D.second;
      int sx = king[0], sy = king[1];
      for (; sx < 8 and sx >= 0 and sy < 8 and sy >= 0; sx += dx, sy += dy) {
        if (isQueen[sx][sy]) {
          res.push_back({sx, sy});
          break;
        }
      }
    }
    return res;
  }
};
