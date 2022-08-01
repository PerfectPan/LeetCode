class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 1, cnt = 0;
        vector<int> res(k, 0);
        for (auto& roll: rolls) {
            roll--;
            if (res[roll] < ans) {
                res[roll] = ans;
                if (++cnt == k) {
                    ans++;
                    cnt = 0;
                }
            }
        }
        return ans;
    }
};

