class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        unordered_map<string, int> mp2;
        
        for (auto& word: words1) {
            mp[word]++;
        }
        for (auto& word: words2) {
            if (mp[word] == 1) {
                mp2[word]++;
            }
        }
        int ans = 0;
        for (auto& [_, cnt]: mp2) {
            ans += cnt == 1;
        }
        return ans;
    }
};
