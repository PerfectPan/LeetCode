class Solution {
public:
    using ll = long long;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> a;
        for (int i = 0; i < nums1.size(); ++i) {
            a.emplace_back(abs(nums1[i] - nums2[i]));
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        a.emplace_back(0);
        ll total = k1 + k2;
        ll i, diff;
        for (i = 1; i < a.size(); ++i) {
            diff = a[i - 1] - a[i];
            ll t = 1LL * diff * i;
            if (t <= total) {
                total -= t;
            } else {
                break;
            }
        }
        if (i == a.size()) {
            return 0LL;
        }
        ll ans = 0;
        for (int j = i; j < a.size(); ++j) ans += 1LL * a[j] * a[j];

        ll x = total / i;
        ll mod = total % i;
        if (mod > 0) {
            ans += (1LL * a[i - 1] - x - 1) * (1LL * a[i - 1] - x - 1) * mod;
        }
        ans += 1LL * (a[i - 1] - x) * (a[i - 1] - x) * (i - mod);

        return ans;
    }
};

