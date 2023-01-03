class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res = 0;
        for (string str : strs) {
            bool all_digits = true;
            for (char c : str) {
                if (!isdigit(c)) {
                    all_digits = false;
                    break;
                }
            }

            if (all_digits) {
                res = max(res, stoi(str));
            } else {
                res = max(res, (int)str.size());
            }
        }

        return res;
    }
};
