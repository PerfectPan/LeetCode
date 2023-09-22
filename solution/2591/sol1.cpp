class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;
        if (money < 0) {
            return -1;
        }
        int cnt = min(money / 7, children);
        money -= cnt * 7;
        children -= cnt;

        if ((children == 0 and money > 0) or (children == 1 and money == 3)) {
            cnt -= 1;
        }
        return cnt;
    }
};
