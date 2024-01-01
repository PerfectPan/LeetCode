// 模拟题意即可，也可以直接排序
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int> Q;
        for (int num: nums) {
            Q.push(-num);
        }
        vector<int> ans;
        while (!Q.empty()) {
            int x = Q.top(); Q.pop();
            int y = Q.top(); Q.pop();
            ans.push_back(-y);
            ans.push_back(-x);
        }
        return ans;
    }
};
