class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = ranges::count_if(word, [](char c) {
            return isupper(c);
        });
        return cnt == 0 or (cnt == 1 and isupper(word[0])) or cnt == word.length();
    }
};
