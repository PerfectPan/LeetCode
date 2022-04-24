class Solution {
public:
    int cnt[26];
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        for (auto& word: words){
            for (int i=0;i<word.size();++i){
                cnt[word[i]-'a']++;
            }
        }
        for (int i=0;i<26;++i){
            if (cnt[i]%n!=0){
                return false;
            }
        }
        return true;
    }
};

