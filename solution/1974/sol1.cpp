class Solution {
public:
    int minTimeToType(string word) {
        int x = 0, ans = word.size();
        for (auto ch : word) {
            int ord = ch - 'a';
            ans += min(abs(ord-x),26-abs(ord-x));
            x = ord;
        }
        return ans;
    }
};
