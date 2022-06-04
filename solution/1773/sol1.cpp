class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        for (auto& item: items) {
            string tp = item[0];
            string col = item[1];
            string name = item[2];
            if (ruleKey == "type") {
                if (ruleValue == tp) {
                    cnt += 1;
                }
            }

            if (ruleKey == "color") {
                if (ruleValue == col) {
                    cnt += 1;
                }
            }

            if (ruleKey == "name") {
                if (ruleValue == name) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};
