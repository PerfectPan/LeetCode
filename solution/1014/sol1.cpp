class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int value = values[0];
        int ans = 0;
        for (int i = 1; i < values.size(); ++i) {
            ans = max(ans, values[i] - i + value);
            value = max(value, values[i] + i);
        }
        return ans;
    }
};
