class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (auto& ch: s) {
            if (!stk.empty()) {
                if ((stk.top() == 'A' && ch == 'B') || (stk.top() == 'C' && ch == 'D')) {
                    stk.pop();
                    continue;
                }
            }
            stk.push(ch);
        }
        return stk.size();
    }
};
