class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flag = true;

        for (int i = 1; i < suits.size(); ++i) {
            if (suits[i] != suits[i - 1]) {
                flag = false;
                break;
            }
        }    
        if (flag) {
            return "Flush";
        }

        int rank[14] = {0};
        for (int i = 0; i < ranks.size(); ++i) {
            rank[ranks[i]]++;
            if (rank[ranks[i]] == 2) {
                flag = true;
            }
            if (rank[ranks[i]] == 3) {
                return "Three of a Kind";
            }
        }

        return flag ? "Pair" : "High Card"; 
    }
};
