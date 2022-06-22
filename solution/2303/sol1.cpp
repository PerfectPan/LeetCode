class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        for (int i = 0; i < brackets.size(); ++i) {
            if (income > brackets[i][0]) {
                ans += 1.0 * (brackets[i][0] - (i > 0 ? brackets[i - 1][0] : 0)) * brackets[i][1] / 100.0;
            } else {
                ans += 1.0 * (income - (i > 0 ? brackets[i - 1][0] : 0)) * brackets[i][1] / 100.0;
                break;
            }
        }
        return ans;
    }
};

