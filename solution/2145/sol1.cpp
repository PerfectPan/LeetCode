class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long mn = 0, mx = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += differences[i];
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        long long diff = mx - mn;
        return max(0LL, upper - lower + 1 - diff);
    }
};
