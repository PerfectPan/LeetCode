class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26, 0);
        for (auto& ch: letters) {
            cnt[ch - 'a']++;
        }

        int n = words.size();
        int total = 1 << n, ans = 0;
        for (int i = 1; i < total; ++i) {
            bool flag = true;
            int res = 0;
            vector<int> tmp(cnt);
            for (int j = 0; j < n && flag; ++j) if (i & (1 << j)) {
                for (int k = 0; k < words[j].size(); ++k) {
                    if (tmp[words[j][k] - 'a'] == 0) {
                        flag = false;
                        break;
                    }
                    tmp[words[j][k] - 'a'] -= 1;
                    res += score[words[j][k] - 'a'];
                }
            }

            if (flag) {
                ans = max(ans, res);
            }
        }
        return ans;
    }
};
