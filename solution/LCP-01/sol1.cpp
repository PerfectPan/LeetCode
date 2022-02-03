class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans=0;
        for (int i=0;i<(int)guess.size();++i){
            ans+=guess[i]==answer[i];
        }
        return ans;
    }
};

