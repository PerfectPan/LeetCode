class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> Q;
        for (int pile: piles) {
            Q.push(pile);
        }
        while (k >= 1) {
            int pile = Q.top(); Q.pop();
            pile -= pile / 2;
            Q.push(pile);
            k--;
        }
        int ans = 0;
        while (!Q.empty()) {
            ans += Q.top();
            Q.pop();
        }
        return ans;
    }
};
