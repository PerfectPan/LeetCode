class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N==1) return 0;
        else if (kthGrammar(N-1,(K+1)/2)) return K&1;
        else return !(K&1);
    }
};

