// 把 nums1 的数字移到另一个空位，又产生了一个新的空位，空位个数不变，所以总是有空位可以让 nums2 的数字填入。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = n + m - 1, i = m - 1, j = n - 1;
        for (; i >= 0 && j >= 0; --tail) {
            if (nums2[j] > nums1[i]) {
                nums1[tail] = nums2[j];
                j--;
            } else {
                nums1[tail] = nums1[i];
                i--;
            }
        }
        for (; i >= 0; --tail, --i) {
            nums1[tail] = nums1[i];
        }
        for (; j >= 0; --tail, --j) {
            nums1[tail] = nums2[j];
        }
    }
};
