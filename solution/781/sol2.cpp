class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        int res = 0;
        for (int ans: answers) {
            int cur = mp[ans];
            if (cur == 0) {
                res += ans + 1;
                mp[ans] = ans;
            } else {
                cur--;
                mp[ans] = cur;
            }
        }
        return res;
    }
};
