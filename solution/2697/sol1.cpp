class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int i = 0, j = (int)s.length() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                s[i] = s[j] = min(s[i], s[j]);
            }
        }
        return s;
    }
};
