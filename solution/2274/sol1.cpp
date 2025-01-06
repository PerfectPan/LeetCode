class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ans = max(special[0] - bottom, top - special.back());
        for (int i = 1; i < special.size(); ++i) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
};
