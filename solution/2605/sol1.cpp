class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        bool flag = false;
        int ans = 1000000000;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    flag = true;
                    ans = min(ans, nums1[i]);
                }
            }
        }
        if (flag) {
            return ans;
        }
        int x = 10, y = 10;
        for (int i = 0; i < nums1.size(); ++i) {
            x = min(x, nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i) {
            y = min(y, nums2[i]);
        }
        if (x > y) swap(x, y);
        return x * 10 + y;
    }
};
