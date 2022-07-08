class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int x = 0, y = 0, p = 0;
        int dir_x[4] = {0, 1, 0, -1};
        int dir_y[4] = {1, 0, -1, 0};
        for (;head != nullptr;) {
          res[x][y] = head->val;
          // cout << x << " " << y <<endl;
          head = head -> next;
          if (!head) {
            break;
          }
          while (!(x + dir_x[p] >= 0 && x + dir_x[p] <= m - 1 && y + dir_y[p] >=0 && y + dir_y[p] <= n - 1 && res[x + dir_x[p]][y + dir_y[p]] == -1)) {
            p = (p + 1) % 4;
          }
          x += dir_x[p];
          y += dir_y[p];
        }
        return res;
    }
};

