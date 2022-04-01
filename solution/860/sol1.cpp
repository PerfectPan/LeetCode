class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0, b = 0;
        for (int i = 0; i < bills.size(); ++i) {
            int m = bills[i];
            if (m == 5) {
                a += 1;
            } else if (m == 10) {
                if (a == 0) {
                    return false;
                }
                a -= 1;
                b += 1;
            } else {
                if (a > 0 && b > 0) {
                    a -= 1;
                    b -= 1;
                } else if (a >= 3) {
                    a -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    } 
};

