class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int a = initialEnergy, b = initialExperience;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a <= energy[i]) {
                ans += energy[i] + 1 - a;
                a = energy[i] + 1;
            }
            if (b <= experience[i]) {
                ans += experience[i] + 1 - b;
                b = experience[i] + 1;
            }

            a -= energy[i];
            b += experience[i];
        }
        return ans;
    }
};
