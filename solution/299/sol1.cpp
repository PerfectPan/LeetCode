class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int A = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                A++;
            } else {
                mp[secret[i]]++;
            }
        }

        int B = 0;
        for (int i = 0; i < n; ++i) {
            if (secret[i] != guess[i] && mp.count(guess[i]) && mp[guess[i]]) {
                B++;
                mp[guess[i]] -=1;
            }
        }

        return to_string(A) + "A" + to_string(B) + "B";
    }
};
