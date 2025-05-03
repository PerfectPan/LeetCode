class Solution {
public:
    int check(int basic, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (basic == tops[i] and basic != bottoms[i]) {
                ans++;
            }
            if (basic != tops[i] and basic != bottoms[i]) {
                return 1e9;
            }
        }
        return ans;
    }  
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();    

        int ans = min({check(tops[0], tops, bottoms), check(tops[0], bottoms, tops),
                        check(bottoms[0], tops, bottoms), check(bottoms[0], bottoms, tops)});

        return ans < 1e9 ? ans : -1;
    }
};
