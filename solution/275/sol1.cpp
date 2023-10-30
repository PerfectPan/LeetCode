class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1, ans = 0;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (citations[mid] >= n - mid) {
                ans = n - mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
