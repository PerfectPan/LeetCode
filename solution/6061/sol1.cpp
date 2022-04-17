class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int maxY = total / cost2;
        long long ans = 0;
        for (int i = 0; i <= maxY; ++i) {
            ans += (total - i * cost2) / cost1 + 1;
        }
        return ans;
    }
};

