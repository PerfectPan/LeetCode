class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int P = 1e9 + 7;
        vector<int> left(n, 0);
        vector<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.back()] >= arr[i]) {
                stk.pop_back();
            }
            left[i] = stk.empty() ? -1 : stk.back();
            stk.push_back(i);
        }
        while (!stk.empty()) {
            stk.pop_back();
        }

        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.back()] > arr[i]) {
                stk.pop_back();
            }
            int r = stk.empty() ? n : stk.back();
            ans = (ans + 1LL * (r - i) * (i - left[i]) % P * arr[i] % P) % P;
            stk.push_back(i);
        }

        return ans;
    }
};
