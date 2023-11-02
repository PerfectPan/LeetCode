class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        unordered_map<int, int> mp;
        auto getId = [](char s) -> int {
            if (s == 'R') {
                return 0;
            }
            if (s == 'G') {
                return 1;
            }
            return 2;
        };
        for (int i = 0; i < n; i += 2) {
            int id = rings[i + 1] - '0';
            mp[id] |= 1 << getId(rings[i]);
        }
        int ans = 0;
        for (auto& [_, v]: mp) {
            if (v == 7) {
                ans++;
            }
        }
        return ans;
    }
};
