class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        string t = "";
        while (i < s.length()) {
            if (s[i] != 'a') {
                break;
            }
            t += s[i];
            i++;
        }
        if (i == s.length()) {
            t[(int)t.length() - 1] = 'z';
            return t;
        }
        for (; i < s.length(); ++i) {
            if (s[i] == 'a') {
                break;
            }
            t += (s[i] - 1);
        }
        for (; i < s.length(); ++i) {
            t += s[i];
        }
        return t;
    }
};
