class Solution {
public:
    int countDigits(int num) {
        int x = num;
        int ans = 0;
        while (num) {
            int p = num % 10;
            if (x % p == 0) {
                ans += 1;
            }
            num /= 10;
        }      
        return ans;
    }
};
