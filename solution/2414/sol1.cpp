class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();
        int l = 0;
        int ans = 0;
        while (l < n) {
            int r = l + 1;
            for (; r < n and s[r] - s[r - 1] == 1; ++r);
            ans = max(ans, r - l);
            l = r;
        }
        return ans;
    }
};
