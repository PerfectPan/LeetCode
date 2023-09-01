// 枚举即可
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        int num1 = total / cost1;
        for (int i = 0; i <= num1; ++i) {
            int left = total - cost1 * i;
            ans += left / cost2 + 1;
        }
        return ans;
    }
};
