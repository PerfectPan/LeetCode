class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            string s = to_string(nums[i]);
            for (int j = i + 1; j < nums.size(); ++j) {
                string s2 = to_string(nums[j]);
                cnt += gcd(s[0] - '0', s2.back() - '0') == 1;
            }
        }

        return cnt;
    }
};
