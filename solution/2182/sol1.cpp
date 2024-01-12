// 贪心
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> rep(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            rep[s[i] - 'a']++;
        }
        string ans = "";
        int b_idx = -1;
        for (;;) {
            int idx = -1;
            for (int i = 25; i >= 0; --i) if (rep[i]) {
                int cnt = min(repeatLimit - (b_idx == i), rep[i]);
                for (int j = 1; j <= cnt; ++j) {
                    ans.push_back('a' + i);
                }
                rep[i] -= cnt;
                idx = i;
                break;
            }
            if (idx == -1) {
                break;
            }
            b_idx = -1;
            for (int j = idx - 1; j >= 0; --j) if (rep[j]) {
                ans.push_back('a' + j);
                rep[j]--;
                b_idx = j;
                break;
            }
            if (b_idx == -1) {
                break;
            }
        }
        return ans;
    }
};
