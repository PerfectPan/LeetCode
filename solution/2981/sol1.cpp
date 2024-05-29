class Solution {
public:
    int maximumLength(string s) {
        int l = 0;
        int ans = -1;
        while (l < s.length()) {
            int r = l;
            for (; r < s.length() and s[r] == s[l]; ++r) {
                if (r - l + 1 > ans) {
                    string str = s.substr(l, r - l + 1);
                    int cnt = 0;
                    for (int i = 0; i < s.length(); ++i) {
                        if (str == s.substr(i, r - l + 1)) {
                            cnt++;
                            if (cnt == 3) {
                                ans = r - l + 1;
                                break;
                            }
                        }
                    }
                }
            }
            l = r;
        }        
        return ans;
    }
};
