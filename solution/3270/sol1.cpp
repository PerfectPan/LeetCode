class Solution {
public:
    int generateKey(int x, int y, int z) {
        int ans = 0;
        for (int pow10 = 1; x && y && z; pow10 *= 10) {
            ans += min({x % 10, y % 10, z % 10}) * pow10;
            x /= 10;
            y /= 10;
            z /= 10;
        }
        return ans;
    }
};
