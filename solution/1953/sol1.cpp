class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long mx = *max_element(milestones.begin(), milestones.end());
        long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - mx;
        if (mx > rest + 1) {
            return rest * 2 + 1;
        }

        return mx + rest;
    }
};
