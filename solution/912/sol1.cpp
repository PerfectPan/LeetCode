class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>vec;
        vector<int>rk(100001, 0);
        for (auto x: nums) {
            rk[x + 50000] += 1;
        }
        for (int i = 0; i <= 100000; ++i) {
            if (rk[i]) {
                for (int j = 1; j <= rk[i]; ++j) {
                    vec.emplace_back(i - 50000);
                }
            }
        }
        return vec;
    }
};

