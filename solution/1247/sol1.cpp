class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int a = 0, b = 0, ans = 0;
        for (int i = 0; i < (int)s1.length(); ++i) {
            a += s1[i]=='x' && s2[i]=='y';
            b += s1[i]=='y' && s2[i]=='x';
        }
        ans += a/2; a %= 2;
        ans += b/2; b %= 2;
        if (a != b) {
            ans = -1;
        } else if (a) {
            ans += 2;
        }

        return ans;
    }
};
