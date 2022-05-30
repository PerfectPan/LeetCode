class Solution {
public:
    int cnt[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 5, 6, 7, 8};
    int getLucky(string s, int k) {
        string t = "";
        int res;
        for (; k--;) {
            res = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    res += cnt[s[i] - 'a'];
                } else {
                    res += s[i] - '0';
                }
            }
            s = to_string(res);
        }
        return res;
    }
};

