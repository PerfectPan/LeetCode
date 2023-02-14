class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> hs;
        int ans = 0, cnt = 0;
        for (int i = 0; i < hours.size(); ++i) {
            cnt += hours[i] > 8 ? 1 : -1;
            if (cnt > 0) {
                ans = max(ans, i + 1);
            } else if (hs.count(cnt - 1)) {
                ans = max(ans, i - hs[cnt - 1]);
            }
            if (!hs.count(cnt)) {
                hs[cnt] = i;
            }
        }
        return ans;
    }
};
