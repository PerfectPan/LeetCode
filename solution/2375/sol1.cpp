class Solution {
public:
    bool flag = false;
    vector<char> res;
    bool isValid(const string& p) {
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == 'I') {
                if (res[i] > res[i + 1]) {
                    return false;
                }
            }
            if (p[i] == 'D') {
                if (res[i] < res[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(int idx, int len, int S, const string& p) {
        if (idx == len) {
            if (isValid(p)) {
                flag = true;
            }
            return;
        }
        for (int i = 0; i < 9; ++i) {
            if (S & (1 << i)) {
                res.push_back(i + '1');
                dfs(idx + 1, len, S ^ (1 << i), p);
                if (flag) {
                    return;
                }
                res.pop_back();
            }
        }
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        int S = (1 << 9) - 1;
        dfs(0, n + 1, S, pattern);
        string ans = "";
        for (auto& ch: res) {
            ans += ch;
        }
        return ans;
    }
};
