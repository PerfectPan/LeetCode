// 4x + 2y = tomatoSlices
// x + y = cheeseSlices
// x = (tomatoSlices - 2 * cheeseSlices) / 2
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices - 2 * cheeseSlices >= 0 && tomatoSlices % 2 == 0) {
            int x = (tomatoSlices - 2 * cheeseSlices) / 2;
            if (cheeseSlices - x >= 0) {
                return { x, cheeseSlices - x };
            }
        }
        return {};
    }
};
