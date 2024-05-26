class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        vector<int> vec(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pre[i + 1][j + 1] = pre[i][j + 1] ^ pre[i + 1][j] ^ pre[i][j] ^ matrix[i][j];
                vec[i * m + j] = pre[i + 1][j + 1];
            }
        }

        nth_element(vec.begin(), vec.begin() + n * m - k, vec.end());
        return vec[n * m - k];
    }
};
