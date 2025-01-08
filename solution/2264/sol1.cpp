class Solution {
public:
    string largestGoodInteger(string num) {
        char ans = 0;
        for (int i = 0; i + 2 < num.size(); ++i) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                ans = max(ans, num[i]);
            }
        }
        return ans ? string(3, ans) : "";
    }
};
