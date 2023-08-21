// 只要保证 L R 的相对位置满足条件即可，即 L 在 start 里的位置一定大于等于 L 在 target 里的位置
// R 在 start 里的位置一定小于等于 R 在 target 里的位置
// 然后字母数量相等，从前往后扫一遍即可
// 时间复杂度 O(n)
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size(), i, j;
        for (i = 0, j = 0; i < n; ++i) {
            if (start[i] == '_') {
                continue;
            }
            while (j < n and target[j] == '_') {
                j++;
            }
            if (j >= n or start[i] != target[j]) {
                return false;
            }
            if (start[i] == 'L' and i < j or start[i] == 'R' and i > j) {
                return false;
            }
            j++;
        }
        for (; j < n; ++j) {
            if (target[j] != '_') {
                return false;
            }
        }
        return true;
    }
};
