class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size(), i = binary.find('0');
        if (i == string::npos) {
            return binary;
        }
        int zero = count(binary.begin(), binary.end(), '0');
        string s(n, '1');
        s[i + zero - 1] = '0';
        return s;
    }
};
