class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int num: nums) {
            cnt += to_string(num).length() % 2 == 0;
        }
        return cnt;
    }
};
