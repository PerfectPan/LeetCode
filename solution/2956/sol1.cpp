class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int ans1 = 0, ans2 = 0;
        vector<int> cnt1(101, 0), cnt2(101, 0);
        for (int& num: nums1) {
            cnt1[num]++;
        }
        for (int& num: nums2) {
            cnt2[num]++;
        }
        for (int num: nums1) {
            ans1 += cnt2[num] > 0;
        }
        for (int num: nums2) {
            ans2 += cnt1[num] > 0;
        }

        return { ans1, ans2 };
    }
};
