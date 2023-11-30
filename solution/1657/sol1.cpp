class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        auto get_cnt = [](const string& str) -> vector<pair<int, int>> {
            vector<pair<int, int>> vec;
            unordered_map<char, int> mp;
            for (int i = 0; i < str.length(); ++i) {
                mp[str[i]]++;
            }
            for (auto& [_, cnt]: mp) {
                vec.push_back({ cnt, _ - 'a' });
            }
            sort(vec.begin(), vec.end());
            return vec;
        };

        auto v1 = get_cnt(word1);
        auto v2 = get_cnt(word2);

        if (v1.size() != v2.size()) {
            return false;
        }
        int s1 = 0, s2 = 0;
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i].first != v2[i].first) {
                return false;
            }
            s1 |= 1 << v1[i].second;
            s2 |= 1 << v2[i].second;
        }

        return s1 == s2;
    }
};
