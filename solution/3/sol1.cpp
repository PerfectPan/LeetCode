class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int cnt = 0;
        // 标号
        vector<int> id(128, -1);
        vector<vector<int>> pre(len + 1, vector<int>(128, 0));
        for (int i = 0; i < len; ++i) {
            if (id[s[i]] == -1) {
                id[s[i]] = cnt++;
            }
            int idx = id[s[i]];
            for (int j = 0; j <= cnt; ++j) {
                pre[i + 1][j] = pre[i][j];
            }
            pre[i + 1][idx]++;
        }
        int ans = 0;
        int lst = 1;
        for (int i = 0; i < len; ++i) {
            int L = max(lst, i + 1), R = len, res = -1;
            while (L <= R) {
                int mid = L + ((R - L) >> 1);
                bool flag = true;
                for (int j = 0; j <= cnt; ++j) {
                    if (pre[mid][j] - pre[i][j] > 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    L = mid + 1;
                    res = mid - i;
                } else {
                    R = mid - 1;
                }
            }
            if (~res) {
                lst = i + res;
                ans = max(ans, res);
            }
        }
        return ans;
    }
};
