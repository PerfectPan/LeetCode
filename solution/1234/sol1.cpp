class Solution {
public:
    int idx(char ch) {
        if (ch == 'Q') {
            return 0;
        }
        if (ch == 'W') {
            return 1;
        }
        if (ch == 'E') {
            return 2;
        }
        return 3;
    }
    int balancedString(string s) {
        int cnt[4] = {0};
        for (int i = 0; i < s.size(); ++i) {
            cnt[idx(s[i])]++;
        }
        int n = s.size();
        for (int i = 0; i < 4; ++i) {
            cnt[i] -= n / 4;
        }
        if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0) {
            return 0;
        }
        int ans = n + 1;
        int c[4] = {0};
        // l + 1 = r 的时候不等式一定不满足，右指针一定会移动，因此不需要判断 l > r
        for (int l = 0, r = -1; l < n; ++l) {
            while (r < n && !(c[0] >= cnt[0] && c[1] >= cnt[1] && c[2] >= cnt[2] && c[3] >= cnt[3])) {
                r++;
                c[idx(s[r])]++;
            }
            if (!(c[0] >= cnt[0] && c[1] >= cnt[1] && c[2] >= cnt[2] && c[3] >= cnt[3])) {
                break;   
            }
            ans = min(ans, r - l + 1);
            c[idx(s[l])]--;
        }

        return ans;
    }
};
