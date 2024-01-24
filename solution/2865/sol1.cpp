class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<int> left, right;
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && maxHeights[i] < maxHeights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                right.push_back(i);
            } else {
                right.push_back(st.top());
            }
            st.push(i);
        }      
        reverse(right.begin(), right.end()); 

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && maxHeights[i] < maxHeights[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                left.push_back(i);
            } else {
                left.push_back(st.top());
            }
            st.push(i);
        } 
        
        vector<long long> left_dp(n, 0);
        vector<long long> right_dp(n, 0);
        for (int i = 0; i < n; ++i) {
            int nxt = left[i];
            if (nxt == i) {
                nxt = -1;
            }
            long long before = nxt == -1 ? 0 : left_dp[nxt];
            left_dp[i] = before + 1LL * (i - nxt) * maxHeights[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            int nxt = right[i];
            if (nxt == i) {
                nxt = n;
            }
            long long before = nxt == n ? 0 : right_dp[nxt];
            right_dp[i] = before + 1LL * (nxt - i) * maxHeights[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, left_dp[i] + right_dp[i] - maxHeights[i]);
        }
        return ans;
    }
};
