// 整个数组异或一下，然后有 1 的位置肯定是有一个数有，有一个数没有，基于此位置有没有 1 将数组分成两组
// 这时候每一组里就只存在一个只出现一次的数字，分别异或一下就知道答案了
// 时间复杂度 O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int num: nums) {
            x ^= num;
        }
        for (int i = 0; i < 32; ++i) {
            if (x & (1 << i)) {
                int A = 0, B = 0;
                for (int num: nums) {
                    if (num & (1 << i)) {
                        A ^= num;
                    } else {
                        B ^= num;
                    }
                }
                return { A, B };
            }
        }
        return { -1, -1 };
    }
};
