class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, cnt = 0;
        for (; l <= r; ) {
            // 如果 l == r，怎么样都要上船，也无所谓这里条件判断是否有误了
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }
            cnt++;
        }
        return cnt;
    }
};
