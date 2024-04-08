// 假设确定了最大值 x，那么这个数组每个数就确定下来了，因为要求每个数不同，且最大最小值差为数组长度 - 1
// 先对数组去重排序，枚举每个数为最大值 x ，然后找 [x - n + 1, x] 范围里有哪些数，剩下的数就是要操作的个数，其他的数都可以变成 [x - n + 1, x] 里对应的没填的数，因为数量是能对上的
// 这个区间一共 n 个数，填了 y 个，剩下 n - y 个没填的坑位，范围外的也有 n - y 个数，可以一一对应
// 可以双指针，也可以二分答案找端点
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int unique_n = nums.size();
        int default_op = n - unique_n;
        int diff = n - 1;
        int res = n - 1;

        for (int i = 0; i + 1 < unique_n; ++i) {
            int l = i + 1, r = unique_n - 1, ans = unique_n - 1;
            while (l <= r) {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] - nums[i] >= diff) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            res = min(res, i + unique_n - 1 - ans + 1 - (nums[ans] - nums[i] == diff) + default_op);
        }

        for (int i = unique_n - 1; i > 0; --i) {
            int l = 0, r = i, ans = 0;
            while (l <= r) {
                int mid = l + ((r - l) >> 1);
                if (nums[i] - nums[mid] >= diff) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            res = min(res, unique_n - 1 - i + ans + 1 - (nums[i] - nums[ans] == diff) + default_op);
        }
        return res;
    }
};
