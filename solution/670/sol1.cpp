class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        int mxIdx = n - 1;
        int p = -1, q;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] > s[mxIdx]) {
                mxIdx = i;
            } else if (s[i] < s[mxIdx]) {
                p = i;
                q = mxIdx;
            }
        }
        if (p != -1) {
            swap(s[p], s[q]);
        }
        return stoi(s);
    }
};
