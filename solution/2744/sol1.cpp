class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        bool seen[26][26]{};
        for (auto &s : words) {
            int x = s[0] - 'a';
            int y = s[1] - 'a';
            if (seen[y][x]) {
                ans++;
            } else {
                seen[x][y] = true;
            }
        }
        return ans;
    }
};
