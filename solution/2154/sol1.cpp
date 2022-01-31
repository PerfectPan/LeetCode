class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        for (;;) {
            bool flag = false;
            for (auto& x: nums) {
                if (x == original) {
                    original *= 2;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        return original;
    }
};

