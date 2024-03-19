class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            string num_str = to_string(num);
            int len = num_str.length();
            int mx = 0;
            for (char ch: num_str) {
                mx = max(mx, ch - '0');
            }
            int t = 0;
            for (int i = 0; i < len; ++i) {
                t = t * 10 + mx;
            }
            sum += t;
        }
        return sum;
    }
};
