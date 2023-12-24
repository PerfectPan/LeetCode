// 推出公式为 f(n) = 2 * n * (n + 1) * (2 * n + 1)
// 二分查找
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 1, r = 1e6, ans = -1;
        auto fn = [](long long n) -> long long {
            return 2 * n * (n + 1) * (2 * n + 1);
        };
        while (l <= r) {
            long long mid = l + ((r - l) >> 1LL);
            if (fn(mid) >= neededApples) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans * 2 * 4;
    }
};
