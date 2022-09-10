class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> res(k, vector<int>(k, 0));
        vector<vector<int>> G(k + 1);
        vector<int> deg(k + 1, 0);
        for (int i = 0; i < rowConditions.size(); ++i) {
            int ab = rowConditions[i][0], be = rowConditions[i][1];

            G[ab].push_back(be);
            deg[be]++;
        }
        queue<int> Q;
        for (int i = 1; i <= k; ++i) {
            if (!deg[i]) {
                Q.push(i);
            }
        }
        vector<int> row(k + 1, 0);
        int num = 0, s = 0;
        while (!Q.empty()) {
            auto x = Q.front(); Q.pop();
            row[x] = num++;
            s++;
            for (int i = 0; i < G[x].size(); ++i) {
                if (--deg[G[x][i]] == 0) {
                    Q.push(G[x][i]);
                }
            } 
        }
        if (s != k) {
            return vector<vector<int>>();
        }


        vector<vector<int>> G2(k + 1);
        vector<int> deg2(k + 1, 0);
        for (int i = 0; i < colConditions.size(); ++i) {
            int ab = colConditions[i][0], be = colConditions[i][1];

            G2[ab].push_back(be);
            deg2[be]++;
        }
        queue<int> Q2;
        for (int i = 1; i <= k; ++i) {
            if (!deg2[i]) {
                Q2.push(i);
            }
        }
        vector<int> col(k + 1, 0);
        int num2 = 0, s2 = 0;
        while (!Q2.empty()) {
            auto x = Q2.front(); Q2.pop();
            col[x] = num2++;
            s2++;
            for (int i = 0; i < G2[x].size(); ++i) {
                if (--deg2[G2[x][i]] == 0) {
                    Q2.push(G2[x][i]);
                }
            } 
        }
        if (s2 != k) {
            return vector<vector<int>>();
        }

        for (int i = 1; i <= k; ++i) {
            res[row[i]][col[i]] = i;
        }
        return res;  
    }
};
