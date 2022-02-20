class Solution {
public:
    int expectNumber(vector<int>& scores) {
        set<int>S;S.clear();
        for (auto x:scores) S.insert(x);
        return (int)S.size();
    }
};

