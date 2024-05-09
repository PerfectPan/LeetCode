class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int ans = 0;
        int a = capacityA, b = capacityB;
        for (int i = 0, j = n - 1; i <= j; ++i, --j) {
            if (i == j) {
                if (a >= b) {
                    {
                        int need = a < plants[i];
                        ans += need;
                        a = (!need ? a : capacityA) - plants[i];
                    }
                } else {
                    {
                        int need = b < plants[i];
                        ans += need;
                        b = (!need ? b : capacityB) - plants[i];
                    }
                }
            } else {
                {
                    int need = a < plants[i];
                    ans += need;
                    a = (!need ? a : capacityA) - plants[i];
                }

                {
                    int need = b < plants[j];
                    ans += need;
                    b = (!need ? b : capacityB) - plants[j];
                }
            }
        }
        return ans;
    }
};
