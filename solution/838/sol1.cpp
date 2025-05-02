class Solution {
public:
    string pushDominoes(string dominoes) {
        int preR = -2, preL = -1;
        for (int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i] == 'L') {
                if (preR < preL) {
                    for (int j = preL + 1; j < i; ++j) {
                        dominoes[j] = 'L';
                    }
                } else {
                    for (int j = preR + 1, k = i - 1; j < k; ++j, --k) {
                        dominoes[j] = 'R';
                        dominoes[k] = 'L';
                    }
                }
                preL = i;
            } else if (dominoes[i] == 'R') {
                if (preR > preL) {
                    for (int j = preR + 1; j < i; ++j) {
                        dominoes[j] = 'R';
                    }
                }
                preR = i;
            }
        }
        if (preR > -1 and preR > preL) {
            for (int i = preR + 1; i < dominoes.size(); ++i) {
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};
