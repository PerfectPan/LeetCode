class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            auto word = words[i];
            if (isVowel(word[0]) && isVowel(word.back())) {
                ans++;
            }
        }
        return ans;
    }
};
