class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        bool hs[1005] = {false};
        int hs2[1005] = {0};

        for (int i = 0; i < items1.size(); ++i) {
            hs[items1[i][0]] = true;
        }
        for (int i = 0; i < items2.size(); ++i) {
            hs2[items2[i][0]] = i + 1;
        }

        for (int i = 0; i < items1.size(); ++i) {
            if (hs2[items1[i][0]]) {
                items1[i][1] += items2[hs2[items1[i][0]] - 1][1];
            }
        }

        for (int i = 0; i < items2.size(); ++i) {
            if (!hs[items2[i][0]]) {
                items1.push_back(items2[i]);
            }
        }

        sort(items1.begin(), items1.end(), [](vector<int>& A, vector<int>& B) -> bool {
            return A[0] < B[0];
        });
        return items1;
    }
};
