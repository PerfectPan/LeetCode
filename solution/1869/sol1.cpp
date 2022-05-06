class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0, zero = 0;
        int pre = -1;
        for (int i = 0, a = 0, b = 0; i < s.size(); ++i) {
            if (s[i] - '0' == pre) {
                if (s[i] == '0') {
                    a++;
                } else {
                    b++;
                }
            } else {
                pre = s[i] - '0';
                if (s[i] == '0') {
                    a = 1;
                } else {
                    b = 1;
                }
            }
            one = max(one, b);
            zero = max(zero, a);
        }
        return one > zero;
    }
};

