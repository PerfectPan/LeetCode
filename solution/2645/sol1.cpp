class Solution {
public:
    int addMinimum(string word) {
        int n = word.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (word[i] == 'a') {
                if (i + 1 < n && word[i + 1] == 'b') {
                    if (i + 2 < n && word[i + 2] == 'c') {
                        i += 2;
                        continue;
                    }
                    i += 1;
                    ans += 1;
                    continue;
                } else if (i + 1 < n && word[i + 1] == 'c') {
                    i += 1;
                    ans += 1;
                    continue;
                }
                ans += 2;
            } else if (word[i] == 'b') {
                if (i + 1 < n && word[i + 1] == 'c') {
                    i += 1;
                    ans += 1;
                    continue;
                }
                ans += 2;
            } else {
                ans += 2;
            }
        }
        return ans;
    }
};
