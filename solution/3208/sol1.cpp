class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n * 2; ++i) {
            if (i > 0 and colors[i % n] == colors[(i - 1) % n]) {
                cnt = 0;
            }
            cnt++;
            ans += i >= n and cnt >= k;
        }
        return ans;
    }
};
