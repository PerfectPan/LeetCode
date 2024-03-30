class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int mx = 0, cnt = 0;
        sort(coins.begin(), coins.end());
        int i = 0;
        while (mx < target) {
            if (i < coins.size() && coins[i]<= mx + 1) {
                mx += coins[i];
                i++;
            } else {
                mx = mx + mx + 1;
                cnt++;
            }
        }
        return cnt;
    }
};
