class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, cnt = 0, len = flowerbed.size();
        while (i < len) {
            if (flowerbed[i] == 1) {
                i++;
                continue;
            }
            int r = i;
            for (; r < len and flowerbed[r] == 0; ++r);
            if (i == 0 and r == len) {
                cnt += (r - i + 1) / 2; 
            } else if (i == 0 or r == len) {
                cnt += (r - i) / 2;
            } else {
                cnt += max(0, r - i - 1) / 2;    
            }
            i = r;
        }
        return cnt >= n;
    }
};
