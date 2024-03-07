class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res(word.length());
        int t = 0;
        for (int i = 0; i < word.length(); ++i) {
            t = (t * 10LL + (word[i] - '0')) % m;
            res[i] = t == 0;
        }
        return res;
    }
};
