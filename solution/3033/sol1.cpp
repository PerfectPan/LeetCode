class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<int> row(matrix[0].size(), -1);
        for (int i = 0; i < matrix[0].size(); ++i){
            for (int j = 0; j < matrix.size(); ++j) {
                row[i] = max(row[i], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix[0].size(); ++i){
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[j][i] == -1) {
                    matrix[j][i] = row[i];
                }
            }
        }

        return matrix;
    }
};
