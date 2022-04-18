class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        int cnt = 0;
        sort(answers.begin() ,answers.end());
        for (int i = 0; i < answers.size(); ++i) {
            if (i == 0 || answers[i] != answers[i - 1] || answers[i] + 1 == cnt) {
                res += answers[i] + 1;
                cnt = 1;
            } else {
                cnt += 1;
            }
        }
        return res;
    }
};

