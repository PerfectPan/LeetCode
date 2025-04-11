class Solution {
public:
    int count(int x) {
        string s = to_string(x);
        if (s.length() % 2) {
            return 0;
        }
        int sz = s.length() / 2;
        int pre = 0, suff = 0;
        for (int i = 0; i < sz; ++i) {
            pre += s[i] - '0';
        }
        for (int i = sz; i < s.length(); ++i) {
            suff += s[i] - '0';
        }
        return pre == suff;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; ++i) {
            ans += count(i);
        }
        return ans;
    }
};
