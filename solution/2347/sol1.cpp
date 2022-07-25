class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flag = true;
        for (int i = 1; i < 5; ++i) {
            if (suits[i] != suits[i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return "Flush";
        }
        flag = true;
        for (int i = 0; i < 5; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                for (int k = j + 1; k < 5; ++k) {
                    if (ranks[i] == ranks[j] && ranks[j] == ranks[k]) {
                        return "Three of a Kind";
                    }
                }
            }
        }

        for (int i = 0; i < 5; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                if (ranks[i] == ranks[j]) {
                    return "Pair";
                }
            }
        }

        return "High Card";
    }
};

