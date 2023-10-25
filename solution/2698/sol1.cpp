// 搜索检查是否满足条件即可
bool flag = false;
void dfs(string& s, int idx, int sum) {
    if (sum < 0) {
        return;
    }
    if (idx == s.size()) {
        if (sum == 0) {
            flag = true;
        }
        return;
    }
    int x = 0;
    for (int i = idx; i < s.size(); ++i) {
        x = x * 10 + s[i] - '0';
        dfs(s, i + 1, sum - x);
        if (flag) {
            return;
        }
    }
}
bool check(int x, int y) {
    string s = to_string(x);
    int len = s.size();
    flag = false;
    dfs(s, 0, y);
    return flag;
}
bool inited = false;
int pre[1005];
void init() {
    for (int i = 1; i <= 1000; ++i) {
        pre[i] = pre[i - 1] + (check(i * i, i) ? i * i : 0);
    }
}
class Solution {
public:
    int punishmentNumber(int n) {
        if (!inited) {
            inited = true;
            init();
        }
        return pre[n];
    }
};
