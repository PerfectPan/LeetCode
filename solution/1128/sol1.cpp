class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < dominoes.size(); ++i) {
            int A = dominoes[i][0], B = dominoes[i][1];
            if (A > B) {
                swap(A, B);
            }
            ans += mp[A * 10 + B];
            mp[A * 10 + B]++;
        }

        return ans;
    }
};
