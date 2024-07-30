class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;

        auto fexp = [&](int a, int n, int P) {
            int res = 1;
            while (n > 0) {
                if (n & 1) {
                    res = res * a % P;
                }

                a = a * a % P;
                n >>= 1;
            }
            return res;
        };
 
        for (int i = 0; i < variables.size(); ++i) {
            auto variable = variables[i];
            int a = variable[0], b = variable[1], c = variable[2], d = variable[3];
            if (fexp(fexp(a, b, 10), c, d) == target) {
                res.push_back(i);
            }
        }


        return res;
    }
};
