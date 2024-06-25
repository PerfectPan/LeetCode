class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        map<int, int> mp;
        int S = (1 << grid[0].size()) - 1;
        for (int i = 0; i < grid.size(); ++i) {
            int num = 0;
            for (int j = 0; j < grid[i].size(); ++j) {
                num = num * 2 + grid[i][j];
            }
            if (num == 0) {
                return {i};
            }
            int x = S ^ num;

            for (int j = x; j; j = (j - 1) & x) {
                if (mp.count(j)) {
                    return { mp[j], i };
                }
            }

            mp[num] = i;
        }
        return {};
    }
};
