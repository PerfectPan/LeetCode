// 把已经输了的人直接删掉，看最后的赢家是不是只有一个即可
// 时间复杂度 O(n + m)
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> is_weak(n);
        for (auto& edge: edges) {
            is_weak[edge[1]] = 1;
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) if (!is_weak[i]) {
            if (ans != -1) {
                return -1;
            }
            ans = i;
        }
        return ans;
    }
};
