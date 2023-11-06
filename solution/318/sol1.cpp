class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> id(words.size(), 0);
        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            for (char ch: word) {
                id[i] |= 1 << (ch - 'a');
            }
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (!(id[i] & id[j])) {
                    ans = max(ans, (int)words[i].length() * (int)words[j].length());
                }
            }    
        }
        return ans;
    }
};
