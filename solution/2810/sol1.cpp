// 当字符串进行反转后，在末尾添加字符等价于「不对字符串进行反转，并且在开头添加字符」。因此，我们可以使用一个双端队列和一个布尔变量 tail 来维护答案
// 最后看是否反转来返回答案字符串
class Solution {
public:
    string finalString(string s) {
        deque<char> q;
        bool tail = true;
        for (char ch: s) {
            if (ch == 'i') {
                tail = !tail;
            } else if (tail) {
                q.push_back(ch);
            } else {
                q.push_front(ch);
            }
        }
        return tail ? string(q.begin(), q.end()) : string(q.rbegin(), q.rend());
    }
};
