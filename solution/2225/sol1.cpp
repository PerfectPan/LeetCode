class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = 0;
        for (int i = 0; i < matches.size(); ++i) {
            n = max({ n, matches[i][0], matches[i][1] });
        }
        vector<int> in(n + 1, 0), out(n + 1, 0);
        
        for (int i = 0; i < matches.size(); ++i) {
            in[matches[i][1]]++;
            out[matches[i][0]]++;
        }
        vector<vector<int>> ans(2, vector<int>{}); 
        for (int i = 0; i < n + 1; ++i) if (in[i] + out[i] > 0) {
            if (in[i] == 0) {
                ans[0].push_back(i);
            }
            if (in[i] == 1) {
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};
