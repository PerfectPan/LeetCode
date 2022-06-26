class Solution {
public:
    int percentageLetter(string s, char letter) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            res += s[i] == letter;
        }
        return (1.0 * res / (int)s.length()) * 100;
    }
};

