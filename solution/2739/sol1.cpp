class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int total = 0;
        while (mainTank) {
            int left = min(5, mainTank);
            mainTank -= left;
            total += left * 10;
            if (left == 5) {
                if (additionalTank > 0) {
                    additionalTank -= 1;
                    mainTank += 1;
                }
            }
        }
        return total;
    }
};
