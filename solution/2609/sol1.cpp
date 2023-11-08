class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int i = 0, n = s.length();
        for (; i < n && s[i] == '1'; ++i);
        int ans = 0;
        while (i < n) {
            int l = i;
            for (; l < n && s[l] == '0'; ++l);
            int r = l;
            for (; r < n && s[r] == '1'; ++r);
            ans = max(ans, 2 * min(l - i, r - l));
            i = r;
        }
        return ans;
    }
};
