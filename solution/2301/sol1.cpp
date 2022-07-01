class Solution {
public:
    bool rep[26 + 26 + 20][26 + 26 + 20];
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        auto idx = [](char ch) -> int {
            if (ch >= 'a' && ch <= 'z') {
                return ch - 'a';
            }
            if (ch >= 'A' && ch <= 'Z') {
                return 26 + ch - 'A';
            }
            return 52 + ch - '0';
        };
        for (int i = 0; i < mappings.size(); ++i) {
            char old = mappings[i][0], nw = mappings[i][1];
            rep[idx(old)][idx(nw)] = true;
        }
        
        int n = s.length(), m = sub.length();
        for (int i = 0; i < n - m + 1; ++i) {
            bool flag = true;
            for (int j = 0, k = i; j < m; ++j, ++k) {
                if (s[k] != sub[j] && !rep[idx(sub[j])][idx(s[k])]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};

