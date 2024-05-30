class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> cnt(26, vector<int>(3));
        for (int i = 0, j = 0; i < s.size(); i = j) {
            while (j < s.size() && s[j] == s[i]) {
                j++;
            }
            int index = s[i] - 'a';
            int len = j - i;
            if (len > cnt[index][0]) {
                cnt[index][2] = cnt[index][1];
                cnt[index][1] = cnt[index][0];
                cnt[index][0] = len;
            } else if (len > cnt[index][1]) {
                cnt[index][2] = cnt[index][1];
                cnt[index][1] = len;
            } else if (len > cnt[index][2]) {
                cnt[index][2] = len;
            }
        }
        
        int res = 0;
        for (auto vec : cnt) {
            res = max({res, vec[0] - 2, min(vec[0] - 1, vec[1]), vec[2]});
        }
        return res ? res : -1;
    }
};
