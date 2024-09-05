class Solution {
public:
    string clearDigits(string s) {
        string t = "";
        for (auto ch: s) {
            if (isdigit(ch)) {
                t.pop_back();
            } else {
                t.push_back(ch);
            }
        }
        return t;
    }
};
