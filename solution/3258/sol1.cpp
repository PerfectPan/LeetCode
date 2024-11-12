class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        for (int l = 0; l < s.length(); ++l) {
            int one = 0, zero = 0;
            for (int r = l; r < s.length(); ++r) {
                if (s[r] == '0') {
                    zero++;
                } else {
                    one++;
                }
                ans += zero <= k or one <= k;
            }      
        }
        return ans;
    }
};
