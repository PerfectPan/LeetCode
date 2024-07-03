class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int t = x, sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }      
        return t % sum == 0 ? sum : -1;
    }
};
