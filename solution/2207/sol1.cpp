class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans = 0, zero = 0, one = 0;
        for (int i = 0; i < text.size(); ++i) {
            if (text[i] == pattern[1]) {
                ans += zero;
                one += 1;
            }
            if (text[i] == pattern[0]) {
                zero += 1;
            }
        }

        return ans + max(one, zero);      
    }
};
