class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i + 3 <= s.length(); ++i) {
            int cnt[26];
            memset(cnt, 0, sizeof(cnt));
            int f = 1;
            for (int j = i; j < i + 3; ++j) {
                if (cnt[s[j] - 'a']) {
                    f = 0;
                    break;
                }
                cnt[s[j]-'a']+=1;
            }
            ans+=f;
        }
        return ans;
    }
};

